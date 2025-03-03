#include<bits/stdc++.h>
using namespace std;

int N; char L;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;

	int num = 1;
	while (1) {
		if (cnt == N) break;
		
		string st = to_string(num);
		bool isOK = 1;
		for (const auto& c : st) {
			if (c == L) isOK = 0;
		}
		if (isOK) {
			++cnt;
		}
		++num;
	}

	cout << num - 1;

	return 0;
}