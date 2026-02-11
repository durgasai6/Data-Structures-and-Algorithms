#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        long long sum=0;
        vector<pair<long long, long long>> points(n);
        for(int i=0;i<n;i++){
            cin>>points[i].first>>points[i].second;
        }
        vector<long long> x;
        vector<long long> y;
        for(int i=0;i<n;i++){
            x.push_back(points[i].first);
            y.push_back(points[i].second);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        long long midx, midy;
        midx = x[n/2];
        midy = y[n/2];
        for(int i=0;i<n;i++){
            sum+= abs(midx - x[i]) + abs (midy - y[i]);
        }
        cout<<sum<<endl;
    }

    
    return 0;
}