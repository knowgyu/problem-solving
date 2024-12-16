#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;

            if (pq.size() < N) {
                pq.push(num);
            }
            else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }

    cout << pq.top();
}
