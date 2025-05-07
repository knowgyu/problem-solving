#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(const vector<string>& a, const vector<string>& b)
{
    return a[0] < b[0];
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end(), cmp);
    
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(const auto& book:book_time)
    {
        // book은 배열로 0에 시작시간 1에 종료시간
        string start = book[0];
        string end = book[1];
        
        int startTime = (start[0]-'0')*10*60 + (start[1]-'0')*60 + (start[3]-'0')*10 + (start[4]-'0');
        int endTime = (end[0]-'0')*10*60 + (end[1]-'0')*60 + (end[3]-'0')*10 + (end[4]-'0') + 10;
        pq.push(endTime); // 10분 청소 시간
        
        cout << start << "  " << end << '\n';
        cout << startTime << "  " << endTime << '\n';
        
        while (!pq.empty() && startTime >= pq.top()) // 만약 현재 시간보다 종료 시간이 느리면 다 빼도 됨.
        {
            cout << "빠지는 중... " << '\n';
            pq.pop();
            
        }
        
        cout << pq.size() << '\n';
        cout << "===================\n";
        answer = max(answer, (int)pq.size());
    }
    
    
    return answer;
}