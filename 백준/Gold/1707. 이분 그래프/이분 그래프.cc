#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	int V, E;
	bool ans = 1;

	vector<int> adj[20001];
	int v[20001] = {};

	cin >> T;
	while (T--) {
		cin >> V >> E;
		
		register int a, b, i;
		for (i = 0; i < E; ++i) {
			cin >> a >> b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}

		for (i = 1; i <= V; ++i) {
			if (!v[i]) {
				queue<int> q;

				q.push(i);
				v[i] = 1;

				while (!q.empty()) {
					int cur = q.front(); q.pop();
					if (!ans) break;
					for (const auto& next : adj[cur]) {
						if (v[next]) {
							if ((v[next] % 2) == (v[cur] % 2)) {
								ans = 0;
								break;
							}
							continue;
						}
						v[next] = v[cur] + 1;
						q.push(next);
					}
				}
			}
			if(!ans) break;
		}

		cout << (ans ? "YES" : "NO") << '\n';

		if (T > 0) {
			for (i = 1; i <= V; ++i) adj[i].clear();
			memset(v, 0, 4 * (V + 1));

			ans = 1;
		}
	}
	return 0;
}