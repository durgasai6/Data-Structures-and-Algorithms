#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;


int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> A(n+2,0),B(n+2,0);

    while(q--){
        long long a,d,l,r;
        cin>>a>>d>>l>>r;

        long long c = (a-(l*d)%mod + mod)%mod;
        A[l] = (A[l]+c)%mod;
        A[r+1] = (A[r+1] - c +mod)%mod;

        B[l] = (B[l] +d)%mod;
        B[r+1] = (B[r+1]-d +mod)%mod;
    }

    vector<long long> prefA(n+1,0),prefB(n+1,0);
    for(int i=1;i<=n;i++){
        prefA[i] = (prefA[i-1] + A[i])%mod;
        prefB[i] = (prefB[i-1] +B[i])%mod;
    }
    vector<long long> ans(n+1);
    for(int i=1;i<=n;i++){
        ans[i] = (prefA[i] + (i*prefB[i])%mod)%mod;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}