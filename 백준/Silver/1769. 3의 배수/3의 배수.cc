#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int ans = 0;
	while (s.length() != 1) {
		int num = 0;
		for (const auto& c : s) {
			num += c - '0';
		}
		s = to_string(num);
		++ans;
	}

	cout << ans << '\n';
	cout << (s == "3" || s == "6" || s == "9" ? "YES" : "NO");

	return 0;
}