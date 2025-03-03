#include<iostream>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	unordered_set<int> us;
	for (int i = 0; i * i <= 1e9; i++) {
		us.insert(i * i);
	}

	int N, M; cin >> N >> M;
	char arr[9][9] = { 0, };
	
	cin.ignore();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = cin.get();
		}
		cin.ignore();
	}

	int mx = -1;
	for (int si = 0; si < N; si++) {
		for (int sj = 0; sj < M; sj++) {
			for (int di = -N + 1; di < N; di++) {
				for (int dj = -M + 1; dj < M; dj++) {
					if (di == 0 && dj == 0) continue;

					string s;
					int i = si, j = sj;

					while (i >= 0 && i < N && j >= 0 && j < M) {
						s.push_back(arr[i][j]);
						
						int num = stoi(s);
						if (us.find(num) != us.end()) mx = max(mx, num);

						i += di;
						j += dj;
					}
				}
			}
		}
	}

	if (N == 1 && M == 1) {
		if (us.find(arr[0][0] - '0') != us.end()) {
			mx = arr[0][0] - '0';
		}
	}

	cout << mx;

	return 0;
}
