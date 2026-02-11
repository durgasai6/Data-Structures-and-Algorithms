#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    while(q--){
        int m;
        cin>>m;
        int ans=0;
        for(int i=0;i<n;i++){
            m-=A[i];
            ans++;
            if(m==0){
                break;
            }
            else if(m<0){
                ans--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}