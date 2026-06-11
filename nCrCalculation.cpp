#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;
const int maxi=1000000;

vector<long long> fact(maxi+1),invfact(maxi+1);

long long power(long long a, long long p){
    long long res=1;
    while(p>0){
        if(p%2==1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        p=p/2;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0]=1;

    for(int i=1;i<=maxi;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

    invfact[maxi]=power(fact[maxi],mod-2);
    for(int i=maxi-1;i>=0;i--){
        invfact[i] = (invfact[i+1]*(i+1))%mod;
    }
    int q;
    cin>>q;
    while(q--){
        long long n,r;
        cin>>n>>r;
        if(r<0 || r>n){
            cout<<0<<endl;
            continue;
        }
        long long ans=fact[n];
        ans=(ans*invfact[n-r])%mod;
        ans=(ans*invfact[r])%mod;

        cout<<ans<<endl;
    }


    return 0;
}