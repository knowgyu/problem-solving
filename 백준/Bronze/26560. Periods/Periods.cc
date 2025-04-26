#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    while (n--) {
        string s;
        getline(cin, s);
        
        if (s.empty() || s.back() != '.') {
            s += '.';
        }
        
        cout << s << '\n';
    }
    
    return 0;
}