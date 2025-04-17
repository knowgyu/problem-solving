#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,R,C;
    cin >> N>>R>>C;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if ((R+C)%2 == (i+j)%2) cout << 'v';
            else cout << '.';
        }
        cout << '\n';
    }
    
    return 0; 
}