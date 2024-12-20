#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector <double> arr(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < 7; i++) printf("%.3f\n", arr[i]);
}