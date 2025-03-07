#include <bits/stdc++.h>
using namespace std;

int N, A, B;

struct Point
{
    int r, c, score;
};
vector<Point> candidates;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A >> B;

    for (int i = 0; i < N; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        candidates.push_back({r, c, s});
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (abs(candidates[i].r - candidates[j].r) < A && abs(candidates[i].c - candidates[j].c) < B)
                ans = max(ans, abs(candidates[i].score - candidates[j].score));

    cout << ans << '\n';

    return 0;
}