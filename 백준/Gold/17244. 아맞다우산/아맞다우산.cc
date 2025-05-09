#include <bits/stdc++.h>
using namespace std;
constexpr int MX = 50 + 5;
constexpr int di[] = { -1,0,1,0 };
constexpr int dj[] = { 0,1,0,-1 };

struct Node {
	int i, j, v;
	int dist;
};

int N, M;
char input[MX][MX];
int arr[MX][MX];
int visited[MX][MX][128];

int si, sj, ei, ej;
int x_cnt;
int ans;

int bfs()
{
	queue<Node> q;
	
	q.push({ si, sj, 0, 0 });
	visited[si][sj][0] = 1;

	while (!q.empty())
	{
		Node c = q.front(); q.pop();
		
		if (c.i == ei && c.j == ej)
			if (c.v == (int)pow(2, x_cnt+1) - 1)
				return c.dist;
			else continue;

		for (int dr = 0;dr < 4;dr++)
		{
			int ni = c.i + di[dr];
			int nj = c.j + dj[dr];
			int nv = c.v;
			int ndist = c.dist + 1;

			if (arr[ni][nj] == 9) continue;
			if (arr[ni][nj] < 7)
				nv |= (1 << arr[ni][nj]);

			if (visited[ni][nj][nv] == 0 || visited[ni][nj][nv] > ndist)
			{
				q.push({ ni, nj, nv, ndist });
				visited[ni][nj][nv] = ndist;
			}


		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			cin >> input[i][j];
			if (input[i][j] == '#') arr[i][j] = 9;
			if (input[i][j] == 'S') { si = i; sj = j; arr[i][j] = 7; }
			else if (input[i][j] == 'E') { ei = i; ej = j; arr[i][j] == 8; }
			else if (input[i][j] == 'X') { arr[i][j] = ++x_cnt; }
		}
		cin.ignore();
	}

	cout << bfs();

	return 0;
}