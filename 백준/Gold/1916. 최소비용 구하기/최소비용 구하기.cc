#include <bits/stdc++.h>
using namespace std;

const int MX = 21e8;

struct Heap {
    int to, cost;
    bool operator>(const Heap& h) const {
        return cost > h.cost;
    }
};
vector<Heap> adj[1001];
int dist[1001];
int N, M, S, E;

void dijk(int start) {
    priority_queue<Heap, vector<Heap>, greater<Heap>> pq;

    fill(dist, dist + N + 1, MX);

    pq.push({ start, 0 });
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().to;
        int d = pq.top().cost;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& e : adj[u]) {
            int v = e.to, cost = e.cost;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({ v, dist[v] });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }
    cin >> S >> E;

    dijk(S);

    cout << dist[E];

    return 0;
}
