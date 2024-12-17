#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    while (1) {
        cin >> s;
        if (s == "end") break;

        bool v = false, valid = true;
        int vc = 0, cc = 0;
        char prev = 0;

        for (int i = 0; s[i]; ++i) {
            char c = s[i];
            bool cv = isVowel(c);

            if (cv) v = true;
            if (cv) {
                vc++;
                cc = 0;
            }
            else {
                cc++;
                vc = 0;
            }
            // 조건2
            if (vc >= 3 || cc >= 3) {
                valid = false;
                break;
            }
            // 조건3
            if (i > 0 && c == prev && !(c == 'e' || c == 'o')) {
                valid = false;
                break;
            }

            prev = c;
        }
        // 조건1
        if (!v) valid = false;
        
        if (valid)
            cout << '<' << s << '>' << " is acceptable." << '\n';
        else
            cout << '<' << s << '>' << " is not acceptable." << '\n';
    }

    return 0;
}
