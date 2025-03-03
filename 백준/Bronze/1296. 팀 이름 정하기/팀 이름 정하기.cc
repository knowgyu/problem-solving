#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<char, int> cnt;
	string name; cin >> name;

	for (const auto& c : name)
		cnt[c]++;

	int N; cin >> N;
	int ans = 0; string astr="zzz";
	for (int i = 0; i < N; i++) {
		string st; cin >> st;
		map<char, int> cnt2;

		for (const auto& c : st)
			cnt2[c]++;

		int L = cnt2['L'] + cnt['L'];
		int O = cnt2['O'] + cnt['O'];
		int V = cnt2['V'] + cnt['V'];
		int E = cnt2['E'] + cnt['E'];

		int val = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

		if (val > ans) {
			ans = val;
			astr = st;
		}
		else if (val == ans) {
			if (astr > st) {
				astr = st;
			}
		}

	}

	cout << astr;

	return 0;
}