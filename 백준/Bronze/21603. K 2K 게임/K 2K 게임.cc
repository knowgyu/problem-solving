#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,K;cin >> N>>K;
    vector<int> ans;
    
    K %= 10;
    for(int i=1;i<=N;i++)
    {
        if (i%10 == K || i%10 == 2*K) continue;
        else ans.push_back(i);
    }
    
    cout << ans.size() <<'\n';
    for(const auto& n:ans)
        cout << n <<' ';
    
    return 0;
}