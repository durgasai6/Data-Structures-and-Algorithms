#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<long long> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+nums[i-1];
    }
    int len=INT_MAX;
    for(int i=0;i<n;i++){
        long long prefixj=prefix[i]+target;
        int low=i+1,high=n;
        int current=-10;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(prefix[mid]>=prefixj){
                current=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(current!=-10){
            len=min(len,current-i);
        }
    }
    if(len==INT_MAX){
        cout<<0<<endl;
    }
    else{
        cout<<len<<endl;
    }
    return 0;
}


