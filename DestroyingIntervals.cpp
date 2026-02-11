#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<long long, long long>> intervals(n);
        for(int i=0;i<n;i++){
            cin>>intervals[i].first>>intervals[i].second;
        }
        sort(intervals.begin(), intervals.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
            return a.second<b.second;
        });

        long long lastpoint = -999999;
        int count=0;

        for(int i=0;i<n;i++){
            if(intervals[i].first > lastpoint){
                lastpoint = intervals[i].second;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}


/*just take the intervals and keep updating your count value and lastpoint selected based on the overlapping conditions*/