#include <bits/stdc++.h>
using namespace std;

int A, B, C, AB, BC, CA;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> A >> B >> C;
        cin >> AB >> BC >> CA;

        int ans = 0;

        for (int ab = 0; ab <= min(A, B); ab++)
        {
            int remainA = A - ab;
            int remainB = B - ab;

            if (BC > CA)
            {
                // BC가 더 가치 있으면 먼저 BC 최대한 만들기
                int bc = min(remainB, C);
                int remainC = C - bc;

                // 남은 A와 C로 CA 만들기
                int ca = min(remainA, remainC);

                ans = max(ans, ab * AB + bc * BC + ca * CA);
            }
            else
            {
                // CA가 더 가치 있거나 같으면 먼저 CA 최대한 만들기
                int ca = min(remainA, C);
                int remainC = C - ca;

                // 남은 B와 C로 BC 만들기
                int bc = min(remainB, remainC);

                ans = max(ans, ab * AB + bc * BC + ca * CA);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}