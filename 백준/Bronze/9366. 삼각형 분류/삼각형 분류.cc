#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int tc = 1;tc <= T;tc++)
    {
        cout << "Case #" << tc << ": ";
        int a, b, c; cin >> a >> b >> c;

        if (a == b && b == c) cout << "equilateral";
        else if (a + b > c && b + c > a && a + c > b)
            if (a == b || b == c || c == a) cout << "isosceles";
            else cout << "scalene";
        else cout << "invalid!";

        cout << '\n';
    }

    
    return 0;
}