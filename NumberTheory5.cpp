#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long power(long long n, long long m){
    long long result = 1;
    n = n%mod;
    
    while(m>0){
        if(m%2 == 1){
            result = (result*n)%mod;
        }
        n = (n*n)%mod;
        m/=2;
    }
    return result;
}


int main(){
    long long n,m;
    cin>>n;
    cin>>m;
    long long v,r,cnt;
    long long ans=0;
    for(long long i=1;i<=n; i = r+1){
        v = n/i;
        r = n/v;
        cnt = r-i+1;
        ans =(ans+ cnt*power(v,m))%mod;
        ans = ans % mod;
    }
    cout<<ans;


    return 0;
}