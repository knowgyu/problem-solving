#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int b = 0, c = 0;
    for(char x : s) {
        if(x == 'B') b++;
        else c++;
    }
    cout << b / 2 + c / 2;
    return 0;
}
