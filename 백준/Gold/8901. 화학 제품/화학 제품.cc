#include <bits/stdc++.h>
using namespace std;

int A, B, C, AB, BC, CA;

void input(), solve();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        input();
        solve();
    }
    return 0;
}

void input()
{
    cin >> A >> B >> C;
    cin >> AB >> BC >> CA;
}

void solve()
{
    int ans = 0;
    // AB, BC 만들면 CA는 자동으로 생성됨.
    // A를 B에 몇개쓰고 C에 몇개쓸건지 생각해야 함.

    // A를 안쓰는것부터 모두 쓰는것까지
    for (int i = 0; i <= A; i++)
    {
        // A를 B에 쓰는 것
        for (int j = 0; j <= B; j++)
        {
            int sm = 0;
            if (j > i)
                break; // B를 더 많이 쓰는건 말이 안됨.

            // AB를 j개만큼 만들기
            sm += AB * j;

            int remain_i = i - j; // AB만들고 남은 A 개수
            int remain_j = B - j; // AB만들고 남은 B 개수
            if (remain_i > 0)
            {
                // A가 남았으면 C에 써야함
                // 만약 C가 더 적게있으면 C만큼 다 쓰기
                if (C <= remain_i)
                    sm += CA * C;
                else
                {
                    // C가 더 있으면 A에 다 넣고
                    sm += CA * remain_i;

                    // BC 만들기
                    sm += BC * min(remain_j, (C - remain_i));
                }
            }
            else
            {
                // B 만드는데에 A를 다 썼음
                sm += BC * min(remain_j, C);
            }

            if (sm > ans)
            {
                ans = sm;
            }
        }
    }
    cout << ans << '\n';
}