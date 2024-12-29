#include<bits/stdc++.h>
using namespace std;
int main() {
	int N; cin >> N;
	
	int arr[128] = {};
	string str; cin >> str;
	for (const auto& c : str)
		arr[c]++;
	

	int ans = 0;
	string s = "BRONZESILVER";
	bool isDone = false;
	while (1) {

		for (const auto& c : s) {
			--arr[c];
			if (arr[c] < 0)
				isDone = true;
		}
		if (isDone) break;
		++ans;
	}

	cout << ans;

	return 0;
}