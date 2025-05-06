#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s; cin >> s;
    for(const auto&c:s)
    {
        switch(c)
        {
            case 'a':
                cout << 4;
                break;
            case 'e':
                cout << 3;
                break;
            case 'i':
                cout << 1;
                break;
            case 'o':
                cout << 0;
                break;
            case 's':
                cout << 5;
                break;
            default:
                cout << c;
                break;
        }
    }
}