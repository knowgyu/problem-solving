#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    auto it = lower_bound(A.begin(), A.end(), K);

    // K 이상인 폭죽의 개수 (단일 사용 가능)
    int ans = A.end() - it;

    auto left = A.begin();
    auto right = prev(it);

    while (left < right)
    {
        if (*left + *right >= K)
        {
            ans++;
            left++;
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << (ans == 0 ? -1 : ans);

    return 0;
}
