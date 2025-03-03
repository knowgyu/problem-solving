#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

int N, M;

struct Edge {
	int to;
	ll cost;
};
vector<vector<Edge>> adj;

int parent[40001][17]; // 2^16 = 65536
ll pacost[40001][17];
int level[40001];
bool v[40001];

int LCA(int A, int B) {

	// A가 무조건 밑에 있음.
	if (level[A] < level[B]) swap(A, B);

	ll Cost = 0;
	for (int k = 16; k >= 0; k--) {
		if (level[A] - level[B] >= pow(2,k)) {
			Cost += pacost[A][k];
			A = parent[A][k];
		}
	}

	// 레벨 맞췄는데 같은 애면
	if (A == B) {
		return Cost;
	}

	for (int k = 16; k >= 0; k--) {
		if (parent[A][k] != parent[B][k]) {
			Cost += pacost[A][k];
			Cost += pacost[B][k];
			A = parent[A][k];
			B = parent[B][k];
		}
	}

	Cost += (pacost[A][0] + pacost[B][0]);
	
	return Cost;
}

void dfs(int n, int node) {
	for (const auto& next : adj[node]) {
		if (v[next.to]) continue;

		level[next.to] = n + 1;
		v[next.to] = 1;
		parent[next.to][0] = node;
		pacost[next.to][0] += next.cost;

		for (int i = 1; i < 17; i++) {
			parent[next.to][i] = parent[parent[next.to][i - 1]][i - 1];
			pacost[next.to][i] = pacost[parent[next.to][i - 1]][i - 1] + pacost[next.to][i-1];
		}

		dfs(n + 1, next.to);
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	adj.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	int root = 1;
	level[root] = 1;
	v[root] = 1;
	dfs(level[root], root);

	cin >> M;
	while (M--) {
		int a, b; cin >> a >> b;
		int ans = LCA(a, b);
		cout << ans << '\n';
	}

	return 0;
}