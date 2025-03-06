#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b; cin>>a>>b;
    
    int ans1,ans2;
    
    ans1 = -a - sqrt(a*a-b);
    ans2 = -a + sqrt(a*a-b);
    
    if (ans1==ans2)
        cout << ans1;
    else
        cout << ans1 <<' '<<ans2;
    return 0;
}