#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	string s; cin >> s;
	int ans = 0;
	for (const auto& c : s) {
		if (c == '1') ++ans;
	}

	cout << ans;

	return 0;
}