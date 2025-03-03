#include <bits/stdc++.h>
int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };
using namespace std;

typedef long long ll;

const int MXN = 1001;
const int MXK = 100;

int N, M, K;

struct Heap {
    int to;
    ll cost;
    bool operator<(Heap r) const {
        return cost > r.cost;
    }
};

vector<Heap> adj[MXN];
priority_queue<ll> dist[MXN];

void dijk() {
    priority_queue<Heap> pq;
    pq.push({ 1, 0 });
    dist[1].push(0);

    while (!pq.empty()) {
        Heap cur = pq.top();
        pq.pop();

        for (const auto& next : adj[cur.to]) {
            ll nextCost = cur.cost + next.cost;

            if (dist[next.to].size() < K) {
                dist[next.to].push(nextCost);
                pq.push({ next.to, nextCost });
            }
            else if (dist[next.to].top() > nextCost) {
                dist[next.to].pop();
                dist[next.to].push(nextCost);
                pq.push({ next.to, nextCost });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    dijk();

    for (int i = 1; i <= N; i++) {
        if (dist[i].size() < K) {
            cout << -1 << "\n";
        }
        else {
            cout << dist[i].top() << "\n";
        }
    }

    return 0;
}