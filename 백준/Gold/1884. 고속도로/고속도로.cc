#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 21e8;
constexpr int MX_N = 101;
constexpr int MX_K = 10001;
constexpr int START = 1;

struct Edge
{
	int d, l, t;
};

struct Heap
{
	int city, dist, toll;

	bool operator<(const Heap& right) const
	{
		return dist > right.dist;
	}
};
vector<Edge> edges[MX_N];
int cost[MX_N][MX_K]; // [도시][통행료] = 최소거리 저장
int K, N, R;

void dijk()
{
	priority_queue<Heap> pq;

	for (int i = 0;i <= N;i++)
		for (int j = 0;j <= K;j++)
			cost[i][j] = MX;

	pq.push({ START,0,0 });
	cost[START][0] = 0;

	while (!pq.empty())
	{
		Heap cur = pq.top(); pq.pop();

		int cur_city = cur.city;
		int cur_dist = cur.dist;
		int cur_toll = cur.toll;

		if (cost[cur_city][cur_toll] < cur_dist) continue; // 이미 들어간게 더 좋음

		for (const auto& nxt : edges[cur_city])
		{
			int nxt_city = nxt.d;				// 도착지
			int nxt_dist = cur_dist + nxt.l;	// 거리
			int nxt_toll = cur_toll + nxt.t;	// 비용

			if (nxt_toll > K) continue; // 예산 넘어감

			if (cost[nxt_city][nxt_toll] > nxt_dist) // 현재 가는 곳 비용보다 더 최단 거리면
			{
				cost[nxt_city][nxt_toll] = nxt_dist;
				pq.push({ nxt_city, nxt_dist, nxt_toll });
			}
		}
	}

	int mn_dist = MX;
	for (int k = 0;k <= K;k++) // 도시 N에서 예산 내 최소거리 찾기
	{
		mn_dist = min(mn_dist, cost[N][k]);
	}

	cout << (mn_dist == MX ? -1 : mn_dist);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N >> R;

	int s, d, l, t;
	for (int i = 0;i < R;i++)
	{
		cin >> s >> d >> l >> t;
		edges[s].push_back({ d,l,t });
	}
	//////////////////////////////////////////

	dijk();

	return 0;
}