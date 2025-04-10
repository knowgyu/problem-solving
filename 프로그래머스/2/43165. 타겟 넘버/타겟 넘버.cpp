#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, ans, tar;
vector<int> numberss;

void dfs(int n, int res)
{
    if (n == N){
        if (res == tar)
            ++ans;
        return;
    }
    
    dfs(n+1, res+numberss[n]);
    dfs(n+1, res-numberss[n]);
}

int solution(vector<int> numbers, int target) {
    N = numbers.size();
    tar = target;
    numberss = numbers;
    
    dfs(0, 0);
    
    return ans;
}