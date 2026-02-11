#include<bits/stdc++.h>
using namespace std;

long long sum(long long x){
    long long ans=0;
    while(x>0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,s;
        cin>>n>>s;
        long long low=1,high=n,ans=LLONG_MIN;
        while(low<=high){
            long long mid= low+(high-low)/2;
            if(mid-sum(mid)>=s){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans<0){
            cout<<0<<endl;
        }
        else{
            cout<<(n-ans +1)<<endl;
        }
    }
    return 0;
}