#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T,N,C; cin >> T;
    while(T--)
    {
        cin >> N >> C;
        cout << (N+C-1)/C <<'\n';
    }
    return 0;
}