#include<iostream>
#include<queue>

using namespace std;
int N;

priority_queue<int> mxpq;
priority_queue<int, vector<int>, greater<>> mnpq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	register int mxCnt = 0;
	register int mnCnt = 0;

	register int tmp;
	while (N--) {
		cin >> tmp;
		if (mxCnt > 0 and tmp <= mxpq.top()) {
			mxpq.push(tmp);
			++mxCnt;
			if (mxCnt - mnCnt > 1) {
				int n = mxpq.top(); mxpq.pop();
				mnpq.push(n);
				--mxCnt;
				++mnCnt;
			}
		}
		else {
			mnpq.push(tmp);
			++mnCnt;
			if (mnCnt > mxCnt) {
				int n = mnpq.top(); mnpq.pop();
				mxpq.push(n);
				--mnCnt;
				++mxCnt;
			}
		}

		cout << mxpq.top() << '\n';
	}
	
	return 0;
}