#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int cnts[10] = {};

	int i = 1;	// 초기 1의 자리수
	while (i <= N) {
		int hi = N / (i * 10);		// 현재보다 높은자리수
		int cur = (N / i) % 10;		
		int lo = N % i;				

		for (int j = 0; j < 10; j++) {
			if (j < cur) 
				cnts[j] += (hi + 1) * i;
			else if (j == cur) 
				cnts[j] += hi * i + lo + 1;
			else 
				cnts[j] += hi * i;
		}

		cnts[0] -= i; // 맨 앞자리가 0인 경우 제외

		i *= 10;
	}

	for (int i = 0; i < 10; i++) cout << cnts[i] << ' ';

	return 0;
}
