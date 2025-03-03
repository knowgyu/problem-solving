#include<bits/stdc++.h>
using namespace std;

bool isLunar(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int months[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int ay, am, ad, by, bm, bd;
	cin >> ay >> am >> ad >> by >> bm >> bd;
	if (by - ay > 1000) {
		cout << "gg";
		return 0;
	}
	else if (by - ay == 1000 && bm > am) {
		cout << "gg";
		return 0;
	}
	else if (by - ay == 1000 && bm == am && bd >= ad) {
		cout << "gg";
		return 0;
	}
	int ans = 0;
	while (ay != by) {
		if ((am <= 2 && isLunar(ay)) || (am > 2 && isLunar(ay + 1))) {
			ans += 366;
		}
		else {
			ans += 365;
		}
		ay++;
	}

	while (am < bm) {
		if (am == 2 && isLunar(ay)) {
			ans += months[am] + 1;
		}
		else {
			ans += months[am];
		}
		am++;
	}
	while (am > bm) {
		if (am == 3 && isLunar(ay)) {
			ans -= (months[am - 1] + 1);
		}
		else {
			ans -= months[am-1];
		}
		am--;
	}


	ans += bd - ad;

	cout << "D-" << ans;
}