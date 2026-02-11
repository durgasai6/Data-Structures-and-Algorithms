#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long> count;
        unordered_map<long long, long long> freq;
        for(int i=0;i<n;i++){
            long long color;
            cin>>color;
            freq[color]++;
        }
        long long answer=0;
        for(auto &x : freq){
            count.push_back(x.second);
        }
        sort(count.begin(),count.end());
        long long l=1,h=n/k;
        while(l<=h){
            long long mid = (l+h)/2;
            long long balls=0;
            for(long long c:count){
                balls+=min(c,mid);
            }
            if(balls>=mid*k){
                answer = mid;
                l = mid+1;
            }
            else{
                h=mid-1;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}