#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N, M;
set<int> tbl[101][101];
unordered_map<int, pair<int, int>> n2l;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int P, L, G;
	for (int i = 0; i < N; i++) {
		cin >> P >> L >> G;
		tbl[L][G].insert(P);
		n2l[P] = { L,G };
	}

	cin >> M;
	string cmd;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == "recommend") {
			int G, x; cin >> G >> x;
			if (x > 0) {
				int mx = 0;
				for (int level = 100; level > 0; level--) {
					if (tbl[level][G].empty()) continue;
					mx = *tbl[level][G].rbegin();
					break;
				}
				cout << mx << '\n';
			}
			else {
				int mn = 1e9;
				for (int level = 1; level <= 100; level++) {
					if (tbl[level][G].empty()) continue;
					mn = *tbl[level][G].begin();
					break;
				}
				cout << mn << '\n';
			}
		}
		else if (cmd == "recommend2") {
			int x; cin >> x;

			if (x > 0) {
				int mx = 0;
				for (int level = 100; level > 0; level--) {
					for (int cate = 1; cate <= 100; cate++) {
						if (tbl[level][cate].empty()) continue;
						mx = max(mx, *tbl[level][cate].rbegin());
					}
					if (mx != 0) break;
				}
				if (mx == 0) cout << -1 << '\n';
				else cout << mx << '\n';
			}
			else {
				int mn = 1e9;
				for (int level = 1; level <= 100; level++) {
					for (int cate = 1; cate <= 100; cate++) {
						if (tbl[level][cate].empty()) continue;
						mn = min(mn, *tbl[level][cate].begin());
					}
					if (mn != (int)1e9)break;
				}
				if (mn == (int)1e9) cout << -1 << '\n';
				else cout << mn << '\n';
			}
		}
		else if (cmd == "recommend3") {
			int x, L; cin >> x >> L;
			if (x > 0) {
				int mn = 1e9;
				for (int level = L; level <= 100; level++) {
					for (int cate = 1; cate <= 100; cate++) {
						if (tbl[level][cate].empty()) continue;
						mn = min(mn, *tbl[level][cate].begin());
					}
					if (mn != (int)1e9) break;
				}
				if (mn == (int)1e9) cout << -1 << '\n';
				else cout << mn << '\n';
			}
			else {
				int mx = 0;
				for (int level = L - 1; level > 0; level--) {
					for (int cate = 1; cate <= 100; cate++) {
						if (tbl[level][cate].empty()) continue;
						mx = max(mx, *tbl[level][cate].rbegin());
					}
					if (mx != 0)break;
				}
				if (mx == 0) cout << -1 << '\n';
				else cout << mx << '\n';
			}
		}
		else if (cmd == "add") {
			int P, L, G;
			cin >> P >> L >> G;
			tbl[L][G].insert(P);
			n2l[P] = { L,G };
		}
		else if (cmd == "solved") {
			int P;
			cin >> P;

			auto LG = n2l[P];
			tbl[LG.first][LG.second].erase(P);
		}
	}

	return 0;
}