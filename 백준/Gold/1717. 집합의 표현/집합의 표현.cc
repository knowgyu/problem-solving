#include<iostream>

using namespace std;

int N, M;

int parent[1000001];

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

	cin >> N >> M;

	for (register int i = 0; i <= N; i++) parent[i] = i;

	register int n, a, b;
	for (register int i = 0; i < M; i++) {
		cin >> n >> a >> b;

		if (n == 0) {
			Union(a, b);
		}
		else {
			if (Find(a)  == Find(b)) {
				cout << "YES"<<'\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}


	return 0;
}