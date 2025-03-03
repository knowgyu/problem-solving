#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e4 + 1;

struct Edge {
	int to;
	ll cost;
};

int N, M;
vector<Edge> adj[MX];
int indegrees[MX];
ll cost[MX];
int START, DEST;

vector<Edge> back[MX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	int u, v;
	ll w;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		indegrees[v]++;

		back[v].push_back({ u,w });
	}

	cin >> START >> DEST;

	queue<int> q;
	q.push(START);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (const auto& e : adj[cur]) {
			indegrees[e.to]--;
			cost[e.to] = max(cost[e.to], cost[cur] + e.cost);

			if (indegrees[e.to] == 0) {
				q.push(e.to);
			}
		}
	}

	cout << cost[DEST] << '\n';

	int ans = 0;
	int visited[MX] = {};

	q.push(DEST);
	visited[DEST] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		for (const auto& e : back[cur]) {
			if ((cost[cur] - e.cost) == cost[e.to]) {
				ans++;
				if (!visited[e.to]) {
					q.push(e.to);
					visited[e.to] = 1;
				}
			}
		}
	}

	cout << ans;

	return 0;
}