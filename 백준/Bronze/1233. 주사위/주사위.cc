#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int DAT[100] = {};

	int mxCnt = 0;
	int mxIdx = 0;
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				DAT[i + j + k]++;
				if (DAT[i + j + k] > mxCnt) {
					mxCnt = DAT[i + j + k];
					mxIdx = i + j + k;
				}
			}
		}
	}

	cout << mxIdx;

	return 0;
}
