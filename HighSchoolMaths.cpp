#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000009;

long long power(long long a, long long p){
    long long result=1;
    a=a%mod;
    while(p>0){
        if(p%2!=0){
            result = (result*a)%mod;
        }
        a=(a*a)%mod;
        p=p/2;
    }
    return result;
}

long long modinv(long long a){
    return power(a,mod-2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,n;
        cin>>a>>b>>n;
        if(a==1){
            long long answer = (1+b)%mod;
            answer=(answer+(n%mod)*(b%mod))%mod;
            cout<<answer<<endl;
        }
        else{
            long long temp =power(a,n);
            long long numerator =(temp-1+mod)%mod;
            long long inverse=modinv(a-1);
            long long gp =(numerator*inverse)%mod;
            long long answer=((temp+(b%mod)*(gp%mod)))%mod;
            cout<<answer<<endl;
        }
    }
    return 0;
}