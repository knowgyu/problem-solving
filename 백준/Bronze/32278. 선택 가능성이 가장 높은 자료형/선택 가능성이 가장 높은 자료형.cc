#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N; cin >> N;
    if (N >= -32768 && N <= 32767) cout << "short";
    else if (N>=-2147483648 && N <= 2147483647) cout << "int";
    else cout << "long long";
    return 0;
}