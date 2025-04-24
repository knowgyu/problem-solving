#include <bits/stdc++.h>
using namespace std;
int q, u, a, c, k, ans;

int main() {
	string str; cin >> str;

	for (const auto&t:str) {
		if (t == 'q') {
			q++;
			ans = max(ans, q);
		}
		else if (t == 'u') {
			u++;
			if (u > q) ans = 21e8;
		}
		else if (t == 'a') {
			a++;
			if (a > u) ans = 21e8;
		}
		else if (t == 'c') {
			c++;
			if (c > a) ans = 21e8;
		}
		else if (t == 'k') {
			k++;
			if (k > c) ans = 21e8;
			q--;u--;a--;c--;k--;
		}
	}
	if (q || u || a || c || k || ans == 21e8) cout << -1;
	else cout << ans;

	return 0;
}