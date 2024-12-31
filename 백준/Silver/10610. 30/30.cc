#include<bits/stdc++.h>
using namespace std;

string s;
int cnt[10];

void solve() {
	int sm = 0;
	for (const auto& c : s) {
		++cnt[c-'0'];
		sm += c - '0';
	}
	// 3의배수 && 10의 배수 아닌 경우
	if (cnt[0] == 0 || sm % 3 != 0) {
		cout << -1;
		return;
	}

	sort(s.rbegin(), s.rend());
	cout << s;
}

int main() {
	cin >> s;

	solve();
		
	return 0;
}