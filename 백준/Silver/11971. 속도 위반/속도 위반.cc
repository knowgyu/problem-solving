#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> lim;
    int p = 0;
    
    for (int i = 0; i < N; i++) {
        int l, s;
        cin >> l >> s;
        lim.push_back({p, p+l});
        lim.push_back({s, 0});
        p += l;
    }
    
    vector<pair<int, int>> arr;
    p = 0;
    
    for (int i = 0; i < M; i++) {
        int l, s;
        cin >> l >> s;
        arr.push_back({p, p+l});
        arr.push_back({s, 0});
        p += l;
    }
    
    int mx = 0;
    
    for (int i = 0; i < M; i++) {
        int a = arr[i*2].first;
        int b = arr[i*2].second;
        int c = arr[i*2+1].first;
        
        for (int j = 0; j < N; j++) {
            int x = lim[j*2].first;
            int y = lim[j*2].second;
            int z = lim[j*2+1].first;
            
            if (max(a, x) < min(b, y)) {
                mx = max(mx, c - z);
            }
        }
    }
    
    cout << max(0, mx);
    return 0;
}