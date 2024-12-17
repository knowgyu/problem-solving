#include<bits/stdc++.h>
#define h first
#define idx second
using namespace std;
const int MX = 5e5+1;

int N;
stack<pair<int,int>> st;
int aLst[MX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;

		while (!st.empty() && st.top().h < num) {
			st.pop();
		}
		aLst[i] = (st.empty()) ? 0 : st.top().idx;
		st.push({ num, i });
	}

	for (int i = 1; i <= N; i++) cout << aLst[i] << ' ';

	return 0;
}