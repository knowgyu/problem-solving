#include <iostream>
using namespace std;

int main() {
    int a;
    string b;
    cin >> a >> b;

    if (b == "bad") {
        cout << 200 * a;
    } else if (b == "cool") {
        cout << 400 * a;
    } else if (b == "great") {
        cout << 600 * a;
    } else if (b == "perfect") {
        cout << 1000 * a;
    } else {
        cout << 0;
    }

    return 0;
}
