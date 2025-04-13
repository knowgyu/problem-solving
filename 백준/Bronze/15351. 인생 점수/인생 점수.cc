#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    string tar;
    
    cin >> N;
    cin.ignore();
    while(N--)
    {
        getline(cin, tar);
        int sum = 0;
        for(const auto& c:tar)
        {
            if (c == ' ') continue;
            sum += c - 'A' + 1;
        }
        
        if (sum == 100) cout << "PERFECT LIFE" << '\n';
        else cout << sum << '\n';
    }
    
    return 0;
}