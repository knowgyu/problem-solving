#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int node;
	Node* next;
};

Node Head[101];
Node Pool[101 * 101];
int pCnt;

int N, M, ans;

void bfs() {
	queue<int> q;
	int v[101] = {};

	q.push(1);
	v[1] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto ptr = Head[cur].next; ptr; ptr = ptr->next) {
			if (v[ptr->node]) continue;

			v[ptr->node] = 1;
			q.push(ptr->node);
			ans++;
		}
	}

}

void Make(int s, int e) {
	Node* nd = &Pool[pCnt++];
	nd->node = e;

	nd->next = Head[s].next;
	Head[s].next = nd;
}

void outputHead(int head) {
	printf("head %d : ", head);

	for (auto* p = Head[head].next; p; p = p->next) printf("%d ", p->node);
	putchar('\n');
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		
		Make(s, e);
		Make(e, s);
	}

	bfs();

	printf("%d\n", ans);

	return 0;
}
