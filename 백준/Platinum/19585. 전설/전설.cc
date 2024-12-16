#include<bits/stdc++.h>
using namespace std;

int C, N, Q;
unordered_set<string> us;

struct Node {
	bool isEnd = false;
	Node* next[26] = { 0, };
};
Node* root = new Node();

void insert(string word) {
	Node* cur = root;
	for (const auto& c : word) {
		int idx = c - 'a';
		
		if (cur->next[idx] == nullptr) {
			Node* next = new Node();
			cur->next[idx] = next;
			cur = cur->next[idx];
		}
		
		else
			cur = cur->next[idx];
	}
	cur->isEnd = true;
}

bool query(string word) {
	Node* cur = root;
	for(int i=0;i<word.length();i++){
		int idx = word[i] - 'a';

		if (cur->isEnd) {
			string chkTeam(word.begin() + i, word.end());
			if (us.count(chkTeam)) return true;
		}

		if (cur->next[idx] == nullptr) return false;
		else cur = cur->next[idx];
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C >> N;
	string color;
	for (int i = 0; i < C; i++) {
		cin >> color;
		insert(color);
	}

	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		us.insert(name);
	}

	cin >> Q;
	string teamName;
	for (int i = 0; i < Q; i++) {
		cin >> teamName;
		cout << (query(teamName) ? "Yes" : "No") << '\n';
	}

	return 0;
}