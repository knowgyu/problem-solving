#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[51][51];
char B[51][51];
bool visited[51][51];

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool bfs(int si, int sj) {
    queue<pair<int, int>> q;

    q.push({ si, sj });
    visited[si][sj] = true;

    char tarB = B[si][sj];
    char colA = A[si][sj];

    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        if (B[ci][cj] != tarB)
            return false;

        for (int dr = 0; dr < 4; dr++) {
            int ni = ci + di[dr];
            int nj = cj + dj[dr];

            if (ni >= 0 && ni < N && nj >= 0 && nj < M && !visited[ni][nj] && A[ni][nj] == colA) {
                q.push({ ni, nj });
                visited[ni][nj] = true;
            }
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> B[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                if (!bfs(i, j)) {
                    cout << "NO" << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES" << "\n";
    return 0;
}
