#include <bits/stdc++.h>
using namespace std;

struct Team
{
    int a,b,c;
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,K,L; cin >>N>>K>>L;
    vector<Team> ans;
    
    int a,b,c;
    for(int i=0;i<N;i++)
    {
        cin >> a>>b>>c;
        if ((a+b+c) >= K && a>=L && b>=L && c>=L)
            ans.push_back({a,b,c});
    }
    
    cout << ans.size() <<'\n';
    for(const auto&team:ans)
    {
        cout << team.a <<' '<<team.b<<' '<<team.c<<' ';
    }
    
    return 0;
}