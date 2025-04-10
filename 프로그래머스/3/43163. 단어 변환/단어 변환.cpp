#include <bits/stdc++.h>
using namespace std;

vector<string> arr;
unordered_map<string, int> v;

string init, dest;

void bfs()
{
    queue<string> q;
    
    q.push(init);
    v[init] = 1;
    
    while(!q.empty())
    {
        string c = q.front(); q.pop();
        if (c == dest)
            return;
        
        for(const string& n:arr)
        {
            if (v[n] != 0) continue;
            
            int cnt = c.size();
            for(int i=0;i<c.size();i++)
            {
                if (c[i] == n[i]) --cnt;
            }
            
            if(cnt != 1) continue;
            
            q.push(n);
            v[n] = v[c]+1;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    arr = words;
    
    init = begin;
    dest = target;
    
    
    bfs();
    
    if (v[dest]) answer = v[dest]-1;
    return answer;
}