#include <iostream>
using namespace std;
int main() {
	int N; cin >> N;
	long long ans = 1;
	for (int i = 1; i <= N; i++)
		ans += 3 * i + 1;
	cout << ans % 45678;
	return 0;
}