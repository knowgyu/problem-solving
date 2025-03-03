#include <bits/stdc++.h>
using namespace std;

queue<int> wait[101];
queue<int> q;
vector<int> tab;

int main() {
	int N, K;
	cin >> N >> K;

	tab.resize(N, 0);

	for (int i = 0;i < K;i++) {
		int num; cin >> num;
		q.push(num);
		wait[num].push(i);
	}

	int time = 0, ans = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		priority_queue<pair<int,int>> distpq;
		
		bool isConnect = false;
		for (int i = 0;i < N;i++) {
			int deviceNum = tab[i]; // i번째 칸에 사용중인 기기 번호
			if (deviceNum == 0 || deviceNum == cur) // 0이면 비어있는 칸 혹은 이미 같은 애면 상관없음.
			{
				tab[i] = cur;
				isConnect = true;

				wait[cur].pop();
				break;
			}
			else			// 사용중인 멀티탭 칸
			{
				// wait에서 front에 있는 애(30번째)와 현재 비교(3번째)
				int dist;
				if (!wait[deviceNum].empty())
					dist = wait[deviceNum].front() - time;
				else
					dist = 999;

				distpq.push({ dist, i }); // 거리, 칸 번호
			}
		}

		if (isConnect) continue; // 빈 곳에 꼽았으면 걍 넘어감
		

		// pq에서 뽑으면 제일 늦게 쓰는애가 나옴.
		auto tmp = distpq.top();
		int tabNum = tmp.second;

		tab[tabNum] = cur;
		wait[cur].pop();
		++ans;
		
		++time;
	}

	cout << ans;

	return 0;
}