#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
unordered_set<char> us;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin.ignore();

    string str;
    while (N--) {
        getline(cin, str);

        bool isOK = false;

        istringstream iss(str);
        string word;
        int wordStart = 0;
        while (iss >> word) {
            char initC = tolower(word[0]);
            if (us.find(initC) == us.end()) {
                us.insert(initC);
                str.insert(wordStart, "[");
                str.insert(wordStart + 2, "]");
                isOK = true;
                break;
            }
            wordStart += word.length() + 1;
        }

        if (!isOK) {
            for (int i = 0; i < str.length(); i++) {
                if (isalpha(str[i])) {
                    char c = tolower(str[i]);
                    if (us.find(c) == us.end()) {
                        us.insert(c);
                        str.insert(i, "[");
                        str.insert(i + 2, "]");
                        isOK = true;
                        break;
                    }
                }
            }
        }

        cout << str << "\n";
    }

    return 0;
}