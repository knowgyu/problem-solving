#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M; cin >> N >> M;
    vector<int> arr(N);
    int sum = 0;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i=0;i<N;i++)
        cout << arr[i] * M / sum << '\n';
    return 0;
}