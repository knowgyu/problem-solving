#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    auto left = s.begin();
    auto right = find(s.begin(), s.end(), ',');

    int ans = 0;
    while (1)
    {
        string tar(left, right);
        ans += stoi(tar);
        
        if (right == s.end()) break;
        
        left = right + 1;
        right = find(left, s.end(), ',');
    }

    cout << ans;

    return 0;
}