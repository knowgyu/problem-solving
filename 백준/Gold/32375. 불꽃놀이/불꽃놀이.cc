#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> A, B;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll K;
    cin >> N >> K;

    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int single = 0;
    for (ll x : A)
    {
        if (x >= K)
            single++;
        else
            B.push_back(x);
    }

    sort(B.begin(), B.end());

    int pair = 0;
    int l = 0, r = B.size() - 1;
    while (l < r)
    {
        if (B[l] + B[r] >= K)
        {
            pair++;
            l++;
            r--;
        }
        else
            l++;
    }

    int ans = single + pair;
    cout << (ans == 0 ? -1 : ans);
    return 0;
}
