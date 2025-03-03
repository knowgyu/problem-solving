#include <iostream>
using namespace std;

int N, M;
int A[50][50], B[50][50];

void flip(int x, int y) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A[x + i][y + j] = 1 - A[x + i][y + j];
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            A[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            B[i][j] = row[j] - '0';
        }
    }

    int ops = 0;

    for (int i = 0; i <= N - 3; ++i) {
        for (int j = 0; j <= M - 3; ++j) {
            if (A[i][j] != B[i][j]) {
                flip(i, j);
                ops++;
            }
        }
    }

    bool equal = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (A[i][j] != B[i][j]) {
                equal = false;
                break;
            }
        }
        if (!equal) break;
    }

    if (equal) {
        cout << ops << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}