#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int dp[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int ans = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;
	

	return 0;
}