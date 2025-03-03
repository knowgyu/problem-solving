#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;

using namespace std;
ll N, k;

ll count(ll num);

int main() {
	cin >> N >> k;

	// 1번 idx ~ N*N번 idx
	long long left = 1;
	long long right = N * N;

	register ll mid;
	ll ans = -1;
	while (left <= right) {
		mid = (left + right) / 2;

		if (count(mid) >= k) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans;

	return 0;
}

ll count(ll num) {
	ll cnt = 0; 
	for (register int i = 1; i <= N; i++) {
		if (i > num) break;
		cnt += min((ll)N, num / (ll)i);
	}
	return cnt;
}