#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int N;
    cin >> N;
    for (int i = 0;i < N;i++) {
        int num; cin >> num;
        st.push(num);
    }

    int ans = 1;
    int mx = st.top(); st.pop();
    while (!st.empty())
    {
        if (st.top() > mx) {
            ++ans;
            mx = st.top();
        }
        st.pop();
    }
    cout << ans;
    return 0;
}