#include <iostream>
using namespace std;
int main() {
    long long p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;
    
    long long num = p1 * p2;
    long long den = q1 * q2 * 2;
    
    cout << (num % den == 0);
    
    return 0;
}