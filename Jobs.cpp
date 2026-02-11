#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<long long> D(n);
        for(int i=0;i<n;i++){
            cin>>D[i];
        }
        vector<long long> L(n);
        for(int i=0;i<n;i++){
            cin>>L[i];
        }
        multiset<pair<long long, long long>> jobs;
        for(int i=0;i<n;i++){
            jobs.insert({D[i],L[i]});
        }
        long long time =0;
        multiset<long long> durations;

        for(auto &j : jobs){
            long long deadline = j.first;
            long long duration = j.second;
            time += duration;
            durations.insert(duration);

            if(time>deadline){
                auto it = prev(durations.end());
                time -= *it;
                durations.erase(it);

            }
        }
        cout<<durations.size()<<endl;
    }
    return 0;
}