#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long a, b;
    while(cin >> a >> b) {
        if(a == 0 && b == 0)
            break;
        long long w = a / b;
        long long r = a % b;
        cout << w << " " << r << " / " << b << "\n";
    }
    return 0;
}
