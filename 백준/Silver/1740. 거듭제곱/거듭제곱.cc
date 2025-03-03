#include<bits/stdc++.h>

using namespace std;

uint64_t pow2(uint64_t num, uint64_t up) {
	uint64_t tmp = 1;
	for (int i = 0; i < up; i++) {
		tmp *= num;
	}

	return tmp;
}

int main() {
	uint64_t N;
	cin >> N;

	uint64_t p = 0;
	uint64_t ans = 0;
	while (N) {
		if (N % 2 == 1) {
			ans += pow2(3, p);
		}
		N = N >> 1;
		++p;
	}
	cout << ans << endl;;
	

	return 0;
}