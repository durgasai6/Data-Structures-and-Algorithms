#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int low= *max_element(a.begin(),a.end());
    int high=0;
    for(int i=0;i<n;i++){
        high+=a[i];
    }
    int ans=high;
    while(low<=high){
        int mid=low + (high -low)/2;
        long long sum=0,count=1;
        for(int i=0;i<n;i++){
            if(sum+a[i]<= mid){
                sum+=a[i];
            }
            else{
                count++;
                sum=a[i];
            }
        }
        if(count<=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    cout<<ans<<endl;
    
    return 0;
}