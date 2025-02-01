#include <iostream>
using namespace std;

int g(int x) {
    if(x == 0) return 0;
    if(x == 2) return 1;
    if(x == 5) return 2;
    return 3;
}

int main(){
    int a, b;
    cin >> a >> b;
    int x = g(a), y = g(b);
    if(x == 3 && y == 3) { cout << "="; return 0; }
    if(x == 3) { cout << "<"; return 0; }
    if(y == 3) { cout << ">"; return 0; }
    if(x == y) { cout << "="; return 0; }
    if((x == 0 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 0))
        cout << ">";
    else
        cout << "<";
    return 0;
}
