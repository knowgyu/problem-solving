#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 5e5 + 5;

int N;
string Nodes;
vector<int> adj[MX];
bool visited[MX];
int parent[MX];

string ans = "";


void bfs()
{
    queue<int> q;
    
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
    
    ans += Nodes[0];

    while (!q.empty())
    {
        char maxChar = 0;

        vector<int> currentLayer;
        int sizeLayer = (int)q.size();

        while (sizeLayer--)
        {
            int c = q.front();
            q.pop();
            currentLayer.push_back(c);

            for (auto& n : adj[c])
            {
                if (!visited[n] && Nodes[n] >= maxChar)
                {
                    maxChar = Nodes[n];
                }
            }
        }

        if (maxChar == 0) break;

        ans.push_back(maxChar);

        for (int c : currentLayer)
        {
            for (auto& n : adj[c])
            {
                if (!visited[n] && Nodes[n] == maxChar)
                {
                    visited[n] = true;
                    parent[n] = c;
                    q.push(n);
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Nodes;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    bfs();
    return 0;
}