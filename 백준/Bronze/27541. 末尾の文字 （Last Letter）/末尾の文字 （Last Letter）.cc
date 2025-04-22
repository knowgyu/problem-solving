#include <iostream>
using namespace std;
int main()
{
    int N; string S; cin >> N >> S;
    if (S.back() == 'G') S.pop_back();
    else S.push_back('G');
    cout << S;
    
    return 0;
}