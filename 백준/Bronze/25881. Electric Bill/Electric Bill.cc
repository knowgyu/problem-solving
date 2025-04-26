#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int r1, r2, n;
    cin >> r1 >> r2 >> n;
    
    while (n--) {
        int kwh;
        cin >> kwh;
        
        int bill;
        if (kwh <= 1000) {
            bill = kwh * r1;
        } else {
            bill = 1000 * r1 + (kwh - 1000) * r2;
        }
        
        cout << kwh << " " << bill << '\n';
    }
    
    return 0;
}