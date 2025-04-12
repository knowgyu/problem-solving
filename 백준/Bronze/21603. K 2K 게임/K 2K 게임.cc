#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,K;cin >> N>>K;
    vector<int> ans;
    
    int K2 = K*2;
    for(int i=1;i<=N;i++)
    {
        if (i%10 == K%10 || i%10 == K2%10) continue;
        else ans.push_back(i);
    }
    
    cout << ans.size() <<'\n';
    for(const auto& n:ans)
        cout << n <<' ';
    
    return 0;
}