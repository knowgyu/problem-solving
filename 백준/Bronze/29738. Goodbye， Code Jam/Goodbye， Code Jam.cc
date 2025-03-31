#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin >> T;
    for(int tc=1;tc<=T;tc++)
    {
        int num; cin >> num;
        string ans;
        if (num <= 25) ans = "World Finals";
        else if (num <= 1000) ans = "Round 3";
        else if (num <= 4500) ans = "Round 2";
        else ans = "Round 1";
        
        cout << "Case #" << tc <<": " << ans <<'\n';
    }
    return 0;
}