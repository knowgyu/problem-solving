#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int ccw = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
    cout << (ccw > 0 ? 1 : ccw < 0 ? -1 : 0);
    return 0;
}
