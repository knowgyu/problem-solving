#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 1e6 + 5;
int N, M, K;
ll arr[MX];
ll tree[4 * MX];

ll init(int node, int left, int right) {
	if (left == right) return tree[node] = arr[left];
	int mid = left + (right - left) / 2;
	return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}

ll update(int node, int left, int right, int idx, ll data) {
	if (idx > right || idx < left) return tree[node];
	if (left == right) return tree[node] = data;
	int mid = left + (right - left) / 2;
	return tree[node] = update(node * 2, left, mid, idx, data) + update(node * 2 + 1, mid + 1, right, idx, data);
}

ll sum(int node, int left, int right, int s, int e) {
	if (s > right || e < left) return 0;
	if (s <= left && right <= e) return tree[node];
	int mid = left + (right - left) / 2;
	return sum(node * 2, left, mid, s, e) + sum(node * 2 + 1, mid + 1, right, s, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	init(1, 0, N - 1);

	ll a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		// update
		if (a == 1) {
			arr[b - 1] = c;
			update(1, 0, N - 1, b - 1, c);
		}
		// query
		else {
			cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}