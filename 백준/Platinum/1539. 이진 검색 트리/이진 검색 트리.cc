#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 3e5;

int N;
map<int, int> tbl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	tbl[0] = -1;
	tbl[MX + 1] = -1;

	cin >> N;
	int data;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> data;

		auto upp = tbl.upper_bound(data);
		auto low = upp--;

		auto cur = max(upp->second, low->second) + 1;
		tbl[data] = cur;
		ans += cur;
		ans++;
	}
	cout << ans;

	return 0;
}