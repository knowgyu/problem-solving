#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> votes(N);
    for(auto &x:votes) cin>>x;
    if(N==1){
        cout<<0;
        return 0;
    }
    int bribes=0;
    while(1){
        int dasom = votes[0];
        int max_vote = 0;
        for(int i=1;i<N;i++) max_vote = max(max_vote, votes[i]);
        if(dasom > max_vote) break;
        int idx=-1;
        for(int i=1;i<N;i++) if(votes[i]==max_vote){idx=i; break;}
        votes[idx]--;
        votes[0]++;
        bribes++;
    }
    cout<<bribes;
}
