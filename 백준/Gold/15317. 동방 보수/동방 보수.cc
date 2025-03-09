#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
ll X;
vector<ll> C, S;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    ll X;
    cin >> N >> M >> X;

    C.resize(N);
    S.resize(M);
    for (int i = 0; i < N; i++)
        cin >> C[i];
    for (int i = 0; i < M; i++)
        cin >> S[i];

    sort(C.begin(), C.end());
    sort(S.begin(), S.end());

    int left = 0, right = min(N, M);
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2; // 배정할 동아리 수

        ll gaps = 0;
        for (int i = 0; i < mid; i++)
        {
            if (S[M - mid + i] < C[i])
                gaps += C[i] - S[M - mid + i];
            if (gaps > X)
                break;
        }

        if (gaps <= X)
        { // mid개의 배정이 가능하면
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
