#include <bits/stdc++.h>
using namespace std;

vector<int> S;
int N, M, L;

int isPossible(int length, int possible_cnt);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> L;

	S.reserve(M);

	for (int i = 0;i < M;i++)
	{
		int num; cin >> num;
		S.push_back(num);
	}
	S.push_back(L);

	for (int i = 0;i < N;i++)
	{
		int q; cin >> q;
		
		int l = 1, r = L;
		int mid, ans = -1;

		while (l < r)
		{
			mid = (l + r) / 2;
			
			if (isPossible(mid, q))
			{
				l = mid+1;
				ans = mid;
			}
			else
			{
				r = mid;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

int isPossible(int length, int possible_cnt) 
{
	int prev = 0;
	int cnt = 0;
	for (const auto& cur : S)
	{
		if (cur - prev >= length)
		{
			++cnt;
			prev = cur;
		}
	}

	if (cnt >= possible_cnt+1) return 1;
	return 0;
}
