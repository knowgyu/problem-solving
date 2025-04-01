#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> st(N);
    for(int i=0;i<N;i++)
        cin >> st[i];

    int ans = 1;
    int mx = st.back(); st.pop_back();
    while (!st.empty())
    {
        if (st.back() > mx) {
            ++ans;
            mx = st.back();
        }
        st.pop_back();
    }
    cout << ans;
    return 0;
}