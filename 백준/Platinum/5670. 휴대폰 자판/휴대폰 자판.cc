#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;

struct Trie {
	map<char, Trie*> next;
	bool isEnd = false;
};

Trie pool[1000001];
int pCnt;

Trie* root;

void insert(string& str) {
	Trie* cur = root;
	for (const auto& c : str) {
		if (cur->next.count(c) == 0) {
			cur->next[c] = &pool[pCnt++];
		}
		cur = cur->next[c];
	}
	cur->isEnd = 1;
}

int query(string& str) {
	Trie* cur = root;
	int typeCnt = 0;
	for (const auto& c : str) {
		// 처음이거나 두개이상이면 입력
		if (cur == root || cur->next.size() > 1 || cur->isEnd) {
			typeCnt++;
		}

		cur = cur->next[c];
	}
	return typeCnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> N) {
		pCnt = 0;
		root = &pool[pCnt++];
		vector<string> wordLst;

		wordLst.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> wordLst[i];
			insert(wordLst[i]);
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans += query(wordLst[i]);
		}

		printf("%.2f\n", (float)ans / (float)N);

		for (int i = 0; i < pCnt; i++) pool[i] = {};
	}

	return 0;
}
