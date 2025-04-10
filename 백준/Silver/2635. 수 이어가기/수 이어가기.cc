#include <bits/stdc++.h>
using namespace std;

int mx;
vector<int> mxarr;

int main()
{
	int N; cin >> N;
	
	if (N == 1) {
		cout << 4 << '\n' << "1 1 0 1";
		return 0;
	}
	for (int i = 0;i < N;i++)
	{
		int a = N, b = i;
		int cnt = 0;
		vector<int> cur_arr;
		cur_arr.push_back(a);
		while (a-b >= 0)
		{
			++cnt;
			int tmp_a = b;
			int tmp_b = a - b;
			a = tmp_a;
			b = tmp_b;
			cur_arr.push_back(a);
		}
		cur_arr.push_back(b);

		if (cnt > mx)
		{
			mx = cnt;
			mxarr = cur_arr;
		}
	}
	cout << mxarr.size() << '\n';
	for (const auto& n : mxarr)
		cout << n << ' ';

	return 0;
}