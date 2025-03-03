#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, C;
vector<int> arr;

int main() {
	cin >> N >> C;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());
	int left = 1;
	int right = arr[N - 1] - arr[0];
	
	int cnt = 0, start = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		cnt = 1;
		start = arr[0];
		for (int i = 1; i < N; i++) {
			if (arr[i] - start >= mid) {
				cnt++;
				start = arr[i];
			}
		}

		if (cnt >= C) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}