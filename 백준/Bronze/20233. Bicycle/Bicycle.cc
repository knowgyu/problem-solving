#include <iostream>
using namespace std;

int main() {
    int a, x, b, y, T;
    cin >> a >> x >> b >> y >> T;
    
    int t1 = (T > 30) ? T - 30 : 0;
    int t2 = (T > 45) ? T - 45 : 0;
    
    int cost1 = a + 21 * t1 * x;
    int cost2 = b + 21 * t2 * y;
    
    cout << cost1 << " " << cost2;
    return 0;
}
