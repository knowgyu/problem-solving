#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int N, Q;
vector<string> A;

vector<int> adj[1001]; // Nodes 1~1000
vector<bool> visited(1001, false);
void bfs(int start, int end);

struct Node
{
    int idx;
    ull val;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> Q;

    A.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 3; i <= N + 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = N + 2; i <= N + Q + 1; i++)
    {
        int start, end;
        cin >> start >> end;

        bfs(start, end);
        fill(visited.begin(), visited.end(), false);
    }

    return 0;
}

void bfs(int start, int end)
{
    queue<Node> q;

    q.push({start, stoull(A[start])});
    visited[start] = true;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if (cur.idx == end)
        {
            cout << cur.val << '\n';
            return;
        }

        for (const auto &n : adj[cur.idx])
        {
            if (visited[n])
                continue; // 방문

            visited[n] = true;
            ull tmp = stoull(to_string(cur.val) + A[n]) % 1000000007;

            q.push({n, tmp});
        }
    }

    return;
}