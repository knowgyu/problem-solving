#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int res = 0;
    for (int i = 0; i < n; i++){
        long long t = a[i];
        int l = 0, r = n - 1;
        bool ok = false;
        while (l < r){
            if (l == i) { l++; continue; }
            if (r == i) { r--; continue; }
            long long s = a[l] + a[r];
            if(s == t){ ok = true; break; }
            else if(s < t) l++;
            else r--;
        }
        if(ok) res++;
    }
    
    cout << res;
    return 0;
}
