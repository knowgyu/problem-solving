#include <bits/stdc++.h>
using namespace std;
unordered_map<string ,int> um;

int main()
{
um["Poblano"]=	1500;
um["Mirasol"]=	6000;
um["Serrano"]=	15500;
um["Cayenne"]=	40000;
um["Thai"]=	75000;
um["Habanero"]=	125000;
    
    int N; cin >> N;
    int ans = 0;
    string s; 
    while(N--)
    {
        cin >> s;
        ans += um[s];
    }
    cout << ans;
}