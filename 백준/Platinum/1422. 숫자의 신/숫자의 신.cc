#include<bits/stdc++.h>
using namespace std;

bool cmp1(const string& a, const string& b) {
	if (a.length() == b.length()) return a + b > b + a;
	return a.length() > b.length();
}

bool cmp2(const string& a, const string& b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int K, N;
	cin >> K >> N;
	int n = N;

	vector<string> arr;
	arr.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}

	if (N>K) {
		sort(arr.begin(), arr.end(), cmp1);
		while (N > K) {
			arr.push_back(arr[0]);
			--N;
		}
	}

	sort(arr.begin(), arr.end(), cmp2);

	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}

	return 0;
}