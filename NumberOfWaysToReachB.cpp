#include<bits/stdc++.h>
using namespace std;
const long long mod =1000000007;
const int maxi = 200000;
vector<long long> fact(maxi+1);
vector<long long> invfact(maxi+1);

long long powering(long long a, long long power){
    long long result=1;
    a=a%mod;
    while(power>0){
        if(power%2 !=0){
            result=(result*a)%mod;
        }
        a=(a*a)%mod;
        power = power/2;
    }
    return result;
}

void factorial(){
    fact[0] =1;
    for(int i=1;i<=maxi;i++){
        fact[i] = (i*fact[i-1])%mod;
    }
    invfact[maxi]=powering(fact[maxi],mod-2);
    for(int i=maxi-1;i>=0;i--){
        invfact[i] = (invfact[i+1]*(i+1))%mod;
    }
}

long long ncr(long long n, long long r){
    if(r<0 || r>n){
        return 0;
    }
    return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}

int main(){
    int t;
    cin>>t;
    factorial();
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<ncr(n+m,n)<<endl;
    }
    return 0;
}