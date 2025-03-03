#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ////////////////////////////// 입력
    // 사람 수 N 파티 수 M
    int N, M;
    cin >> N >> M;

    // 진실을 아는 사람 수
    int T;
    cin >> T;

    set<int> truth;
    for (int i = 0; i < T; i++) {
        int person; cin >> person;
        truth.insert(person);
    }

    // 파티마다 오는 사람의 수와 번호
    vector<vector<int>> party(M);
    for (int i = 0; i < M; i++) {
        int P; cin >> P;

        party[i].resize(P);

        for (int j = 0; j < P; j++)
            cin >> party[i][j];
    }

    ////////////////////////////////////////
        
    bool flag = true; // truth 집합에 변화가 있는지
    while (flag) {
        flag = false;
        // 파티 돌면서

        for (int i = 0; i < M; i++) {
            // i번째 파티에 진실 있는지
            bool isTrue = false;
            for (auto& p : party[i]) {
                if (truth.count(p)) {
                    isTrue = true;
                    break;
                }
            }

            // 진실 있으면
            if (isTrue) {
                for (auto& p : party[i]) {
                    if (!truth.count(p)) {
                        truth.insert(p);
                        flag = true;
                    }
                }
            }
        }
    }


    // 진실 없는 파티 갯수
    int ans = 0;
    for (int i = 0; i < M; i++) {
        bool isTrue = false;
        for (auto& p : party[i]) {
            if (truth.count(p)) {
                isTrue = true;
                break;
            }
        }

        if (!isTrue)
            ans++;
    }

    cout << ans;
}