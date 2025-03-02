#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int d1,d2,d3; cin >> d1>>d2>>d3;
    float a,b,c;
    
    a = (d2 - d3 + d1)/2.0;
    b = (d1 - d2 + d3)/2.0;
    c = (d3 - d1 + d2)/2.0;
    
    if (a>0 && b>0 && c>0)
    {
        cout << 1 << '\n';
        cout << fixed << setprecision(1) << a << ' '<< b << ' '<<c;
    }
    else
    {
        cout << -1 << '\n';
    }
    

    return 0;
}