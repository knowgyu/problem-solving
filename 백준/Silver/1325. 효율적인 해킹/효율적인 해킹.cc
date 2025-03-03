#include<bits/stdc++.h>
using namespace std;
int N, M;

vector<vector<int>> adj;


int bfs(int s) {
	queue<int> q;

	bool v[10001] = {};

	q.push(s);
	v[s] = 1;
	
	register int cnt = 0;
	while (!q.empty()) {
		int c = q.front(); q.pop();

		for (const auto& n : adj[c]) {
			if (v[n] != 0) continue;
			
			q.push(n);
			v[n] = 1;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	cin >> N >> M;
	adj.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		// adj[u].push_back(v);
		adj[v].push_back(u);
	}


	int alst[10001] = {};
	int mx = 0;
	for (int i = 1; i <= N; i++) {
		alst[i] = bfs(i);
		mx = max(mx, alst[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (alst[i] == mx) {
			cout << i << ' ';
		}
	}

	return 0;
}