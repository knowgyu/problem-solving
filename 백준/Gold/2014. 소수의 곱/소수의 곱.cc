#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int K, N;
priority_queue<ll,vector<ll>,greater<>> q;
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> N;

	ll tmp;
	primes.reserve(K);
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		q.push(tmp);
		primes.push_back(tmp);
	}

	ll c = 0;
	int idx = 0;
	while (idx < N) {
		for (int i = 0; i < K; i++) {
			c = q.top();
			ll result = primes[i] * c;

			if (result > INT_MAX) break;

			q.push(result);

			if (c % primes[i] == 0) break;
		}

		q.pop();
		idx++;
	}

	cout << c;

	return 0;
}
