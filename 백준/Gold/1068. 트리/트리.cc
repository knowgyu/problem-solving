#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, deleteNode, leafCount = 0, root;
vector<int> adj[51];

int dfs(int node) {
    if (node == deleteNode) return -1;
    if (adj[node].empty()) {
        leafCount++;
        return 0;
    }
    for (const auto& child : adj[node]) {
        int result = dfs(child);
        if (result == -1 && adj[node].size() == 1) {
            leafCount++;
        }
    }
    return 0;
}

void solve() {
    dfs(root);
    cout << leafCount;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            root = i;
        } else {
            adj[parent].push_back(i);
        }
    }

    cin >> deleteNode;
    solve();

    return 0;
}