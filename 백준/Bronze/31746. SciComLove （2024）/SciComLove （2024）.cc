#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    
    string s = "SciComLove";
    
    if (n % 2 == 1)
        reverse(s.begin(), s.end());
    
    cout << s;
    
    return 0;
}