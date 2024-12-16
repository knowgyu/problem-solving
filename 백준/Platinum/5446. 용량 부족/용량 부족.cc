#include<bits/stdc++.h>
using namespace std;

struct Trie {
	bool isEnd = false;
	int erase = 0;
	int Nerase = 0;
	map<char, Trie*> next;
    ~Trie() {
    for(auto&pair:next) delete pair.second;
}
};
int pCnt;
Trie* root;
int ans;

// 지워야 하는 파일
void insert1(string word) {
	auto cur = root;
	for (const auto c : word) {
		cur->erase++;

		if (cur->next.find(c) == cur->next.end()) {
			Trie* nxt = new Trie();
			// Trie* nxt = &pool[pCnt++];
			cur->next[c] = nxt;
		}
		cur = cur->next[c];
	}
	cur->isEnd = true;

}

// 지우면 안되는 파일
void insert2(string word) {
	auto cur = root;
	for (const auto c : word) {
		cur->Nerase++;

		if (cur->next.find(c) == cur->next.end()) {
			Trie* nxt = new Trie();
			// Trie* nxt = &pool[pCnt++];
			cur->next[c] = nxt;
		}
		cur = cur->next[c];
	}
	cur->Nerase++;
}

void recurRemove(Trie* cur) {
	// 내 밑에 자식 얘 싹 다 지워도 되는 애면
	if (cur->Nerase == 0) {
		ans++;
		return;
	}

	if (cur->isEnd) {
		ans++;
	}

	// 밑에 가서 확인하기
	for (const auto& nxt : cur->next) {
		Trie* nxtPtr = nxt.second;
		/*
		if (nxtPtr->isEnd)
		{
			ans++;
		}*/
		recurRemove(nxtPtr);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC; cin >> TC;
	while (TC--) {
		ans = 0;
		root = new Trie();

		int N1, N2;

		string data;
		cin >> N1;
		for (int i = 0; i < N1; i++) {
			cin >> data;
			insert1(data);
		}

		cin >> N2;
		for (int i = 0; i < N2; i++) {
			cin >> data;
			insert2(data);
		}

		recurRemove(root);

		cout << ans << '\n';
	}
	return 0;
}