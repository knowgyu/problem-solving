#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	set<int> A;
	set<int> B;

	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		A.insert(tmp);
	}
	for (int j = 0; j < M; j++) {
		int tmp; cin >> tmp;
		B.insert(tmp);
	}
	
	vector<int> ans;
	for (const auto& n : A) {
		auto it = B.find(n);
		if (it != B.end()) continue;
		ans.push_back(n);
	}

	cout << ans.size() << endl;
	for (const auto& n : ans)
		cout << n << ' ';


	return 0;
}