#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long N; cin >> N;
    vector<long long> arr(N);
    for(long long i=0;i<N;i++) cin >> arr[i];
    
    long long S; cin >> S;
    
    long long ans = 0;
    for(const auto& size:arr)
        ans += (size + S-1) / S;
    cout << ans*S;
    
    return 0;
}