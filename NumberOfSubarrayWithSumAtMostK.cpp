#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long sum=0,answer=0;
        int l=0;
        for(int r=0;r<n;r++){
            sum+=a[r];
            while(sum>k && l<=r){
                sum-=a[l];
                l++;
            }
            answer+=(r-l+1);
        }
        cout<<answer<<endl;
    }
    return 0;
}