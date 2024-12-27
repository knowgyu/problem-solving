#include<bits/stdc++.h>
using namespace std;

string convBase(int num, int base) {
	string ret = "";
	
	if (num == 0)
		return "0";

	while (num) {
		int remain = num % base;
		ret.push_back(char(remain));
		num /= base;
	}

	return ret;
}

bool checkPal(string& str) {
	string str2(str.rbegin(),str.rend());

	if (str == str2)
		return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int num; cin >> num;
		
		bool flagPal = false;

		for (int base = 2; base <= 64; base++) {

			string str = convBase(num, base);

			if (checkPal(str)) {
				flagPal = true;
				break;
			}
		}

		cout << flagPal << '\n';
	}


	return 0;
}