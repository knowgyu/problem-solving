#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    for(int i=0;i<N;i++){
        if (arr[i] <= L)
            ++L;
        else
            break;
    }

    cout << L;
    
    return 0;
}