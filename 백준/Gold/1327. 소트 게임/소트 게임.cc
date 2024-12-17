#include<bits/stdc++.h>
using namespace std;

int N, K;
string arr;
string narr;
unordered_map<string, int> um;

int bfs() {
	queue<string> q;

	q.push(arr);
	um[arr] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == narr) {
			return um[cur] - 1;
		}

		for (int i = 0; i < N - K + 1; i++) {
			string tmp(cur);

			for (int j = i, jj = i; j < i + K / 2; j++,jj--) {
				swap(tmp[j], tmp[jj + K - 1]);
			}
			
			if (um[tmp] == 0 || um[cur] + 1 < um[tmp]) {
				q.push(tmp);
				um[tmp] = um[cur] + 1;
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	arr.reserve(N);

	char tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	};

	// 오름차순 확인용 배열
	narr = arr;
	sort(narr.begin(), narr.end());
	
	cout << bfs();

	return 0;
}