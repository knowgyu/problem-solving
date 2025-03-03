#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    if(!N){
        cout << 0;
        return 0;
    }
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int ans = 1, s = 0;
    for(int i = 0; i < N; i++){
        if(s + v[i] <= M){
            s += v[i];
        } else {
            ans++;
            s = v[i];
        }
    }
    cout << ans;
}