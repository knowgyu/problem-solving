#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;
struct pll {
	ll val;
	ll idx;
};

using namespace std;

const int MX = 1e5 + 5;
int N;
int arr[MX];
ll treeSm[4 * MX];
// ll treeMn[4 * MX];
pll treeMn[4 * MX];
ll ans;

pll minp(pll a, pll b) {
	if (a.val != b.val) return (a.val < b.val ? a : b);
	return (a.idx < b.idx ? a : b);
}

ll initSm(int n, int l, int r) {
	if (l == r) return treeSm[n] = arr[l];
	int m = l + (r - l) / 2;
	return treeSm[n] = initSm(n * 2, l, m) + initSm(n * 2 + 1, m + 1, r);
}

pll initMn(int n, int l, int r) {
	if (l == r) return treeMn[n] = { arr[l], l };
	int m = l + (r - l) / 2;
	return treeMn[n] = minp(initMn(n * 2, l, m), initMn(n * 2 + 1, m + 1, r));
}

ll querySm(int n, int l, int r, int s, int e) {
	if (e < l || s > r) return 0;
	if (s <= l && r <= e) return treeSm[n];
	int m = l + (r - l) / 2;
	return querySm(n * 2, l, m, s, e) + querySm(n * 2 + 1, m + 1, r, s, e);
}

pll queryMn(int n, int l, int r, int s, int e) {
	if (e < l || s > r) return { LLONG_MAX,-1 };
	if (s <= l && r <= e) return treeMn[n];
	int m = l + (r - l) / 2;
	return minp(queryMn(n * 2, l, m, s, e), queryMn(n * 2 + 1, m + 1, r, s, e));
}

void getMax(int l, int r) {
	if (l > r)return;
	pll mn = queryMn(1, 0, N - 1, l, r);
	ll sm = querySm(1, 0, N - 1, l, r);
	ll score = mn.val * sm;
	ans = max(ans, score);

	getMax(l, mn.idx - 1);
	getMax(mn.idx + 1, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	initSm(1, 0, N - 1);
	initMn(1, 0, N - 1);

	getMax(0, N - 1);
	cout << ans;

	return 0;
}
