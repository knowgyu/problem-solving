#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 1e6 + 5;
vector<int> arr[MX];
int parent[MX];
int dp[MX][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    // 후위 순위
    vector<int> order;
    stack<int> st;
    st.push(1);

    parent[1] = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        order.push_back(u);
        for (int v : arr[u])
            if (v != parent[u])
            {
                parent[v] = u;
                st.push(v);
            }
    }

    // 리프에서 루트로
    for (int i = N - 1; i >= 0; --i)
    {
        int u = order[i];
        dp[u][1] = 1;
        for (const int &v : arr[u])
            if (v != parent[u])
            {
                dp[u][0] += dp[v][1];                // u 미선택 → v 강제 선택
                dp[u][1] += min(dp[v][0], dp[v][1]); // u 선택 → v 자유
            }
    }

    cout << min(dp[1][0], dp[1][1]) << '\n';
}
