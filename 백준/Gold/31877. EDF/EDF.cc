#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Heap
{
    ll w, t, d;

    bool operator<(const Heap &R) const
    {
        return tie(d, t) > tie(R.d, R.t);
    }
};
priority_queue<Heap> pq;
vector<Heap> addJobs;

int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t, d;
        cin >> t >> d;
        pq.push({0, t, d});
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int w, t, d;
        cin >> w >> t >> d;
        addJobs.push_back({w, t, d});
    }
    sort(addJobs.begin(), addJobs.end(), [](const Heap &l, const Heap &r)
         { return l.w < r.w; });

    ll cur_time = 0;
    int idx = 0;

    // 큐에 할 일이 남았거나, 앞으로 도착할 작업이 남아있는 동안
    while (!pq.empty() || idx < M)
    {
        while (idx < M && addJobs[idx].w <= cur_time)
        {
            pq.push(addJobs[idx]);
            idx++;
        }

        if (pq.empty())
        {
            ll next_arrive = addJobs[idx].w;
            cur_time = next_arrive;
            pq.push(addJobs[idx]);
            idx++;
            continue;
        }

        auto job = pq.top();
        pq.pop();

        if (job.w > cur_time)
        {
            cur_time = job.w;
        }

        ll next_arrive = (idx < M ? addJobs[idx].w : LLONG_MAX);
        if (cur_time + job.t <= next_arrive)
        {
            cur_time += job.t;
            if (cur_time > job.d)
            {
                cout << "NO\n";
                return 0;
            }
        }
        else
        {
            ll work_time = next_arrive - cur_time;
            job.t -= work_time;
            cur_time = next_arrive;
            if (cur_time > job.d)
            {
                cout << "NO\n";
                return 0;
            }
            pq.push(job);
        }
    }

    cout << "YES\n"
         << cur_time << "\n";
    return 0;
}