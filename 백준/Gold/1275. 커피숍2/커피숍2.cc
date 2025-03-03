#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1e5 + 5;

int N, Q;
int arr[MX];
ll tree[MX * 4];

ll init(int n, int l, int r) {
	if (l == r) return tree[n] = arr[l];
	int m = (l + r) / 2;
	return tree[n] = init(n * 2, l, m) + init(n * 2 + 1, m + 1, r);
}

ll update(int n, int l, int r, int idx, ll data) {
	if (idx > r || idx < l) return tree[n];
	if (l == r) return tree[n] = data;
	int m = (l + r) / 2;
	return tree[n] = update(n * 2, l, m, idx, data) + update(n * 2 + 1, m + 1, r, idx, data);
}

ll query(int n, int l, int r, int s, int e) {
	if (s > r || e < l) return 0;
	if (s <= l && r <= e) return tree[n];
	int m = (l + r) / 2;
	return query(n * 2, l, m, s, e) + query(n * 2 + 1, m + 1, r, s, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> arr[i];

	init(1, 0, N - 1);

	ll x, y, a, b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);
		cout << query(1, 0, N - 1, x - 1, y - 1) << '\n';
		update(1, 0, N - 1, a - 1, b);
	}

	return 0;
}