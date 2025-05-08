#include<bits/stdc++.h>
using namespace std;

int N, M;
set<int> tbl[101];
unordered_map<int, int> num2level;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		tbl[b].insert(a);
		num2level[a] = b;
	}

	cin >> M;
	string cmd;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == "recommend") {
			cin >> a;
			if (a > 0) {
				for (int i = 100; i > 0; i--) {
					if (tbl[i].empty()) continue;
					cout << *tbl[i].rbegin() << '\n';
					break;
				}
			}
			else {
				for (int i = 1; i <= 100; i++) {
					if (tbl[i].empty()) continue;
					cout << *tbl[i].begin() << '\n';
					break;
				}
			}
		}
		else if (cmd == "add") {
			cin >> a >> b;
			tbl[b].insert(a);
			num2level[a] = b;
		}
		else if (cmd == "solved") {
			cin >> a;

			int level = num2level[a];
			tbl[level].erase(a);
		}
	}

	return 0;
}