#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
    char* p;
    bool __END_FLAG__, __GETLINE_FLAG__;
public:
    explicit operator bool() { return !__END_FLAG__; }
    INPUT() {
        struct stat st; fstat(0, &st);
        p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
    bool IsBlank(char c) { return c == ' ' || c == '\n'; }
    bool IsEnd(char c) { return c == '\0'; }
    char _ReadChar() { return *p++; }
    char ReadChar() {
        char ret = _ReadChar();
        for (; IsBlank(ret); ret = _ReadChar());
        return ret;
    }
    template<typename T> T ReadInt() {
        T ret = 0; char cur = _ReadChar(); bool flag = 0;
        for (; IsBlank(cur); cur = _ReadChar());
        if (cur == '-') flag = 1, cur = _ReadChar();
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return flag ? -ret : ret;
    }
    string ReadString() {
        string ret; char cur = _ReadChar();
        for (; IsBlank(cur); cur = _ReadChar());
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return ret;
    }
    double ReadDouble() {
        string ret = ReadString();
        return stod(ret);
    }
    string getline() {
        string ret; char cur = _ReadChar();
        for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (__GETLINE_FLAG__) __END_FLAG__ = 1;
        if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
        return ret;
    }
    friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
    char write_buf[SZ];
    int write_idx;
public:
    ~OUTPUT() { Flush(); }
    explicit operator bool() { return 1; }
    void Flush() {
        write(1, write_buf, write_idx);
        write_idx = 0;
    }
    void WriteChar(char c) {
        if (write_idx == SZ) Flush();
        write_buf[write_idx++] = c;
    }
    template<typename T> int GetSize(T n) {
        int ret = 1;
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
        return ret;
    }
    template<typename T> void WriteInt(T n) {
        int sz = GetSize(n);
        if (write_idx + sz >= SZ) Flush();
        if (n < 0) write_buf[write_idx++] = '-', n = -n;
        for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
        write_idx += sz;
    }
    void WriteString(string s) { for (auto& c : s) WriteChar(c); }
    void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
    if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
    else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in;
}

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
    if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
    else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out;
}

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////
#define MKALB 0
#define RMALB 1
#define INSERT 2
#define DELETE 3
#define CA 4

inline int getCmd(const string& cmd) {
	if (cmd[0] == 'm') return MKALB;
	if (cmd[0] == 'r') return RMALB;
	if (cmd[0] == 'i') return INSERT;
	if (cmd[0] == 'd') return DELETE;
	if (cmd[0] == 'c') return CA;
}

struct Directory {
	string dirName;
	Directory* parDir;
	map<string, Directory*> childDirs;
	set<string> curImgs;

	Directory() {
		parDir = nullptr;
		childDirs.clear();
		curImgs.clear();
	}
};

Directory root;
Directory pool[100000];
int pCnt;

// RMALB시 재귀적으로 폴더 지우는 중
void getRMcnt(Directory* curDir, int& albumCnt, int& imgCnt) {
	albumCnt += curDir->childDirs.size();
	imgCnt += curDir->curImgs.size();
	for (const auto& next : curDir->childDirs) {
		getRMcnt(next.second, albumCnt, imgCnt);
	}
}

int main() {
	fastio;

	int N; cin >> N;

	string cmd, val;
	int imgCnt, albumCnt;

	Directory* curDir = &root;
	curDir->dirName = "album";

	for (int i = 0; i < N; i++) {
		cin >> cmd >> val;

		switch (getCmd(cmd)) {
		case MKALB:
			if (curDir->childDirs.find(val) == curDir->childDirs.end()) {
				// Directory* child = new Directory();
				Directory* child = &pool[pCnt++];
				child->dirName = val;
				child->parDir = curDir;

				curDir->childDirs[val] = child;
			}
			else {
				cout << "duplicated album name" << '\n';

			}
			break;

		case RMALB:
			albumCnt = 0, imgCnt = 0;
			if (curDir->childDirs.empty()) {
				cout << albumCnt << ' ' << imgCnt << '\n';
				break;
			}

			if (val == "-1") {
				albumCnt++;
				auto it = curDir->childDirs.begin();
				getRMcnt(it->second, albumCnt, imgCnt);
				curDir->childDirs.erase(it->first);
			}
			else if (val == "0") {
				for (const auto& cur : curDir->childDirs) {
					albumCnt++;
					getRMcnt(cur.second, albumCnt, imgCnt);
				}
				curDir->childDirs.clear();
			}
			else if (val == "1") {
				albumCnt++;
				auto it = curDir->childDirs.rbegin();
				getRMcnt(it->second, albumCnt, imgCnt);
				curDir->childDirs.erase(it->first);
			}
			else if (curDir->childDirs.find(val) != curDir->childDirs.end()) {
				albumCnt++;
				getRMcnt(curDir->childDirs[val], albumCnt, imgCnt);
				curDir->childDirs.erase(val);
			}

			cout << albumCnt << ' ' << imgCnt << '\n';
			break;

		case INSERT:
			if (curDir->curImgs.find(val) == curDir->curImgs.end()) {
				curDir->curImgs.insert(val);
			}
			else {
				cout << "duplicated photo name" << '\n';
			}
			break;

		case DELETE:
			imgCnt = 0;
			if (curDir->curImgs.empty()) {
				cout << imgCnt << '\n';
				break;
			}

			if (val == "-1") {
				auto it = curDir->curImgs.begin();
				curDir->curImgs.erase(*it);
				++imgCnt;
			}
			else if (val == "0") {
				imgCnt = curDir->curImgs.size();
				curDir->curImgs.clear();
			}
			else if (val == "1") {
				auto it = curDir->curImgs.rbegin();
				curDir->curImgs.erase(*it);
				++imgCnt;
			}
			else if (curDir->curImgs.find(val) != curDir->curImgs.end()) {
				curDir->curImgs.erase(val);
				++imgCnt;
			}
			cout << imgCnt << '\n';
			break;

		case CA:
			if (val == ".." && curDir->parDir != nullptr) {
				curDir = curDir->parDir;
			}
			else if (val == "/") {
				curDir = &root;
			}
			else if (curDir->childDirs.find(val) != curDir->childDirs.end()) {
				curDir = curDir->childDirs[val];
			}
			cout << curDir->dirName << '\n';
			break;
		}
	}

	return 0;
}
