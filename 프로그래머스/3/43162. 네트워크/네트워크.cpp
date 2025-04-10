#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 200;
int v[MX];
vector<int> adj[MX];

void bfs(int start)
{
    queue<int> q;
    
    q.push(start);
    v[start] = 1;
    
    while(!q.empty())
    {
        int c = q.front(); q.pop();
        
        for(const int& n:adj[c])
        {
            if(v[n]) continue;
            
            q.push(n);
            v[n] = 1;
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if (computers[i][j])
                adj[i].push_back(j);
    }
    
    for(int i=0;i<n;i++)
        if (v[i] == 0) {
            bfs(i);
            ++answer;
        }
    
    return answer;
}