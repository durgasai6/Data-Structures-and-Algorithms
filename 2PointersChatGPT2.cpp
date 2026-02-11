#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,ans=0;
    int sum=0;
    for(int r=l;r<n;r++){
        sum+=a[r];
        while(sum>k){
            sum-=a[l];
            l++;
        }
        ans+=(r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}