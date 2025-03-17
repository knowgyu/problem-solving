#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 5e5 + 5;

vector<int> adj[MX];

queue<int> q;
bool v[MX] = {};

int main()
{
	int N, W; cin >> N >> W;
	
	for (int i = 0;i < N-1;i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 리프 노드의 수 구하기.

	q.push(1);
	v[1] = true;

	int ans = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		bool isLeaf = true;
		for (const auto& nxt : adj[cur])
		{
			if (v[nxt]) continue;

			q.push(nxt);
			v[nxt] = 1;
			isLeaf = false;
		}

		ans += isLeaf;
	}

	cout << fixed << setprecision(10) << (double)W / ans;


	return 0;
}