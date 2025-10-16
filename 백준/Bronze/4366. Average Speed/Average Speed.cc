#include <bits/stdc++.h>
using namespace std;

int toSec(string t) {
    int h = stoi(t.substr(0,2));
    int m = stoi(t.substr(3,2));
    int s = stoi(t.substr(6,2));
    return h*3600 + m*60 + s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    double dist = 0, speed = 0;
    int prev = 0;

    while (getline(cin, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string time; ss >> time;
        
        int cur = toSec(time);
        dist += speed * (cur - prev) / 3600.0;
        prev = cur;
        
        if (ss >> speed);
        else cout << time << " " << fixed << setprecision(2) << dist << " km\n";
    }
}
