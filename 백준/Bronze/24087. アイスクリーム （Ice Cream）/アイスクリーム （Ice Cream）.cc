#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, a, b;
    cin >> s >> a >> b;
    
    if (s <= a)
        cout << 250 << '\n'; 
    else {
        int extra = ceil((double)(s - a) / b);
        cout << 250 + extra * 100 << '\n';
    }
    
    return 0;
}