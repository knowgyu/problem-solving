#include <iostream>
using namespace std;

string s;
bool isA, isB, isC;

int main()
{
    cin >> s;
    
    for(const auto& c:s)
    {
        switch(c){
            case 'A': isA = true; break;
            case 'B': isB = true; break;
            case 'C': isC = true; break;
            default: break;
        }
    }
    
    if (isA){
        for(const auto& c:s){
            switch(c){
                case 'A': case 'B': case 'C': case 'D': case'F': cout << 'A'; break;
                default: cout << c;
            }
        }
    }
    
    else if (isB){
        for(const auto& c:s){
            switch(c){
                case 'A': case 'B': case 'C': case 'D': case'F': cout << 'B'; break;
                default: cout << c;
            }
        }
    }
    
    else if (isC){
        for(const auto& c:s){
            switch(c){
                case 'A': case 'B': case 'C': case 'D': case'F': cout << 'C'; break;
                default: cout << c;
            }
        }
    }
    
    else{
        for(const auto& c:s){
            cout << 'A';
        }
    }
    
    
    return 0; 
}