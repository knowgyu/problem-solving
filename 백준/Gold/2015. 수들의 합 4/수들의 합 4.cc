#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

int N, K;
int arr[MX];
int presum[MX];
unordered_map<int, int> um;

int main() {
	// freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		presum[i] = presum[i - 1] + arr[i];
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		if (presum[i] == K) ans++;
		ans += um[presum[i] - K];
		um[presum[i]]++;
	}

	cout << ans;

	return 0;
}
