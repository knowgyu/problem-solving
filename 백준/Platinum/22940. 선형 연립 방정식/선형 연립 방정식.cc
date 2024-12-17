#include <bits/stdc++.h>
using namespace std;

double arr[10][10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		double d = arr[i][i];
		for (int j = i; j <= N; j++) {
			arr[i][j] /= d;
		}

		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			double w = arr[j][i];
			for (int k = i; k <= N; k++) {
				arr[j][k] -= arr[i][k] * w;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << round(arr[i][N]) << ' ';
	}

	return 0;
}
