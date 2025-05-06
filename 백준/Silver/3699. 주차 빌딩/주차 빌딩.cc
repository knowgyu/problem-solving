#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int h, l;
        cin >> h >> l;
        
        vector<vector<int>> g(h, vector<int>(l));
        int m = 0;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                cin >> g[i][j];
                m = max(m, g[i][j]);
            }
        }
        
        int s = 0;
        for (int k = 1; k <= m; k++) {
            int f = -1, p = -1;
            
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < l; j++) {
                    if (g[i][j] == k) {
                        f = i;
                        p = j;
                        break;
                    }
                }
                if (f != -1) break;
            }
            
            if (f < 0) continue;
            
            int a = p;
            int b = (p == 0) ? 0 : l - p;
            int d;
            
            if (a <= b) 
            {
                d = a;
                vector<int> temp = g[f];
                g[f].clear();
                
                for (int j = p; j < l; j++) g[f].push_back(temp[j]);
                for (int j = 0; j < p; j++) g[f].push_back(temp[j]);
            } 
            else {
                d = b;
                vector<int> temp = g[f];
                g[f].clear();
                
                for (int j = l - d; j < l; j++) g[f].push_back(temp[j]);
                for (int j = 0; j < l - d; j++) g[f].push_back(temp[j]);
            }
            
            g[f][0] = -1;
            s += 20 * f + 5 * d;
        }
        
        cout << s << '\n';
    }
    
    return 0;
}