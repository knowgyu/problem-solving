#include <bits/stdc++.h>
using namespace std;
int main() {

	unordered_map<int, int> um;

	int N;
	cin >> N;

	int mx = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		um[num]++;
		mx = max(mx, um[num]);
	}

	if (((N + 1) / 2) >= mx)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}