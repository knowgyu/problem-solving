#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int mat[301][301];
int parents[301];

struct Edge {
    int from, to, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<Edge> edges;

int Find(int a) {
    if (parents[a] == a) return a;
    return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB) return;
    parents[rootB] = rootA;
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cost;
    for (int i = 1; i <= n; i++) {
        cin >> cost;
        edges.push_back({ 0, i, cost });
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edges.push_back({ i, j, mat[i][j] });
        }
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i <= n; i++) parents[i] = i;

    int sum = 0;
    for (int i = 0; i < edges.size(); i++) {
        int node1 = edges[i].from;
        int node2 = edges[i].to;
        int cost = edges[i].cost;

        if (Find(node1) != Find(node2)) {
            Union(node1, node2);
            sum += cost;
        }
    }

    cout << sum << endl;
}
