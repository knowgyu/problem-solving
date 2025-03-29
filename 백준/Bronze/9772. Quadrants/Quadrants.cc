#include <bits/stdc++.h>
using namespace std;

int main()
{
    float x,y;
    while (1)
    {
        cin >> x >> y;
        if (x==0 && y ==0) break;
        
        if (x==0 || y==0) cout << "AXIS";
        else if (x > 0 && y > 0) cout << "Q1";
        else if (x > 0 && y < 0) cout << "Q4";
        else if (y > 0) cout << "Q2";
        else cout << "Q3";
        cout << '\n';
    }
    cout << "AXIS";
    return 0;
}