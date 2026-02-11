#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long modularinverse(long long x){
    long long ans = 1;
    long long power = mod-2;

    while(power>0){
        if(power%2!=0){
            ans = (ans*x)%mod;
        }
        x = (x*x)%mod;
        power/=2;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        long long dia = ((n % mod)*((n-1)%mod)*((n-2)%mod)*((n-3)%mod))%mod;
        dia= (dia*modularinverse(24))%mod;
        cout<<dia<<endl;
    }
    return 0;
}