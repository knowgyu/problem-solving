#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        string ans, best;
        for (int i = 0; i < n; i++) {
            string s, low;
            cin >> s;
            low = s;
            transform(low.begin(), low.end(), low.begin(), ::tolower);

            if (i == 0 || low < best) {
                best = low;
                ans = s;
            }
        }
        cout << ans << '\n';
    }
}
