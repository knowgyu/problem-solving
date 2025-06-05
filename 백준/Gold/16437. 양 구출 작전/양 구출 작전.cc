#include <iostream>
#include <vector>
#include <stack>
typedef long long ll;
using namespace std;
const int MX = 123456 + 5;

int N;
vector<int> adj[MX];
ll cnt[MX];
int parent[MX] = {};
int v[MX] = {};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 2;i <= N;i++)
	{
		char t;
		ll a, p; 
		cin >> t >> a >> p;

		if (t == 'S')
			cnt[i] = a;	// 양 a
		else
			cnt[i] = -1 * a;	// 늑대 -a

		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	// 후위 순위
	vector<int> order;


	stack<int> st;
	st.push(1);

	parent[1] = 0;
	while (!st.empty())
	{
		int u = st.top(); st.pop();
		order.push_back(u);
		for (int v : adj[u])
			if (v != parent[u])
			{
				parent[v] = u;
				st.push(v);
			}
	}

	for(int i=order.size()-1;i>=0;i--)
	{
		int c = order[i]; // 후위순서
		
		if (cnt[c] > 0) // 만약 양 있어서 올릴 수 있으면
		{
			int p = parent[c];
			
			cnt[p] += cnt[c];
		}
	}
	cout << cnt[1];

	return 0;
}