#include<bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int num = 1;
	while (1) {
		int ten = pow(10, num++);
		if (N > ten) {
			N = (N + ten / 2) / ten;
			N *= ten;
		}
		else {
			break;
		}
	}

	cout << N;

	return 0;
}