#include<bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	int sm = 0;

    int arr[1000] = {};
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
        arr[i] = tmp;
        sm += (i & 1) ? -arr[i] : arr[i];
	}

	sm /= 2;

	cout << sm << endl;
    for (int i = 0; i < N - 1; i++) {
        sm = arr[i] - sm;
        cout << sm << endl;
    }

	return 0;
}