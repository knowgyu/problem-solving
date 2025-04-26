#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    
    int a = 0, b = 0;
    
    for (char c : s) {
        if (c == 'A') a++;
        else b++;
    }
    
    cout << a << " : " << b << '\n';
    
    return 0;
}