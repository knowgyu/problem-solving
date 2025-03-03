#include<bits/stdc++.h>

using namespace std;

int parent[201];

int Find(int A) {
	if (A == parent[A]) return A;
	return parent[A] = Find(parent[A]);
}

void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);
	if (rootA == rootB) return;
	parent[rootB] = rootA;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int arr[201][201] = {};
	for (int i = 0; i <= 200; i++) parent[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				Union(i, j);
			}
		}
	}

	
	int from, to;
	cin >> from;
	for (int i = 1; i < M; i++) {
		cin >> to;
		if (Find(from) == Find(to)) {
			from = to;
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}