#include<bits/stdc++.h>

using namespace std;


int main() {
	int N, M;
	cin >> N >> M;

	int num[1001] = {};
	for (int i = 0; i < M; i++) {
		int tmp; cin >> tmp;
		num[tmp] = 1;
	}

	register int ans = INT_MAX;
	register int i, j, k;
	for (i = 1; i <= 1000; i++) {
		if (num[i]) continue;
		for (j = i; j <= 1000; j++) {
			if (num[j]) continue;
			for (k = j; k <= 1001; k++) {
				if (num[k]) continue;
				
				ans = min(ans, abs(N - i * j * k));
			}
		}
	}
	cout << ans;

	return 0;
}