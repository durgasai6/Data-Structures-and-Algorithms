#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> A(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        vector<int> Products(A.begin(),A.end());
        sort(Products.begin(),Products.end());
        int ans=0;
        for(int i=0;i<n;i++){
            m-=Products[i];
            ans++;
            if(m==0){
                break;
            }
            else if(m<0){
                ans--;
                break;
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}