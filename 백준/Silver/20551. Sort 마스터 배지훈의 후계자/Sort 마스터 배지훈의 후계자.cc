#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> A;
unordered_map<int, int> um;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    A.resize(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    
    sort(A.begin(),A.end());
    for(int i=0;i<N;i++){
        if(um.count(A[i])) continue;
        um[A[i]] = i;
    }
    
    for(int i=0;i<M;i++)
    {
        int D; cin >> D;
        if(um.count(D)) cout << um[D] << '\n';
        else cout << -1 << '\n';
    }
    
    
    return 0;
}