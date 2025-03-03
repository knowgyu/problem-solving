#include<bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;
int dp[MX];

int main() {
	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 2] + dp[i - 1])%15746;

	cout << dp[N];

	return 0;
}