#include <bits/stdc++.h>
using namespace std;

int N,M,a,b,x;

int main()
{
    cin >> N>>M;
    while(N--)
    {
        cin >> x;
        a = max(a,x);
    }
    while(M--)
    {
        cin >> x;
        b = max(b,x);
    }
    
    cout << a+b;
    
    return 0;
}