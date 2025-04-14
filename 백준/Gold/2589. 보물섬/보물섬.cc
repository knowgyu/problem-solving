#include <bits/stdc++.h>
using namespace std;

int N,M;
char arr[51][51];
int v[51][51];
constexpr int di[] = {-1,0,1,0};
constexpr int dj[] = {0,1,0,-1};

struct Node{
    int i,j;
};

inline int bfs(int si, int sj)
{
    queue<Node> q;
    memset(v,0,sizeof(v));
    
    q.push({si, sj});
    v[si][sj] = 1;

    int ret = 0;
    while(!q.empty())
    {
        auto c = q.front(); q.pop();
        
        for(int dr=0;dr<4;dr++)
        {
            int ni = c.i+di[dr];
            int nj = c.j+dj[dr];
            
            if (ni<0 || nj<0||ni>=N||nj>=M || v[ni][nj] ||arr[ni][nj] != 'L') continue;
            
            q.push({ni, nj});
            v[ni][nj] = v[c.i][c.j] + 1;
            ret = max(ret, v[ni][nj]);
        }
    }
    
    return ret - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N>> M;
    for(int i=0;i<N;i++) {
        for (int j=0;j<M;j++) cin >> arr[i][j];
        cin.ignore();
    }
    
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (arr[i][j] == 'L')
                ans = max(ans,bfs(i, j));
        }
    }
    
    cout << ans;
    
    return 0; 
}