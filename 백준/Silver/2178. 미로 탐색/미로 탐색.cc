#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1,0,1,0};
const int dj[] = {0,1,0,-1};

int N,M,ans;
char arr[101][101];

int bfs()
{
    queue<pair<int,int>> q;
    int v[101][101] = {};
    
    q.push({0, 0});
    v[0][0] = 1;
    
    while(!q.empty())
    {
        pair<int,int> c = q.front(); q.pop();
        
        if (c.first == N-1 && c.second == M-1)
            return v[N-1][M-1];
        
        for(int dr=0;dr<4;dr++)
        {
            int ni = c.first + di[dr];
            int nj = c.second + dj[dr];
            
            if (ni<0 || nj<0 || ni>=N || nj >= M || v[ni][nj] || arr[ni][nj] == '0') continue;
            
            q.push({ni ,nj});
            v[ni][nj] = v[c.first][c.second] + 1;
        }
    }
    return 0;
}

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) 
            cin >> arr[i][j];
        cin.ignore();
    }
    
    cout << bfs();
    
    return 0;
}