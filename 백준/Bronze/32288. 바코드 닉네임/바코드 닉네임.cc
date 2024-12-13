#include <iostream>
using namespace std;

int main(){
    int x; string s;
    cin >> x >> s;
    for(auto &c:s){
        c ^= 0x20;
        cout << c;
    }
    
    return 0;
}