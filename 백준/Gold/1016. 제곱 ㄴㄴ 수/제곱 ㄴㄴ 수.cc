#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e6 + 1;
vector<bool> isPri(MX, 1);
vector<ll> priSqr;
vector<bool> sqrFree;
ll m, M, r;
int maxSqr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> M;
    r = M - m + 1;
    maxSqr = sqrt(M);

    for (int i = 2; i * i <= maxSqr; i++)
        if (isPri[i])
            for (int j = i * i; j <= maxSqr; j += i)
                isPri[j] = 0;

    for (int i = 2; i <= maxSqr; i++)
        if (isPri[i]) priSqr.push_back((ll)i * i);

    sqrFree.resize(r, 1);
    for (ll ps : priSqr)
        for (ll j = ((m + ps - 1) / ps) * ps; j <= M; j += ps)
            sqrFree[j - m] = 0;

    cout << count(sqrFree.begin(), sqrFree.end(), 1) << "\n";

    return 0;
}