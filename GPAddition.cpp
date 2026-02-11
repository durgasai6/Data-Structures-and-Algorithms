#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

long long powercalc(long long x, long long pow){
    long long result =1;
    x%=mod;
    while(pow>0){
        if(pow%2 !=0){
            result = (result*x)%mod;
        }
        x = (x*x)%mod;
        pow=pow/2;
    }
    return result;
}

int main(){
    int n,q;
    long long k;
    cin>>n>>q>>k;
    vector<long long> A(n+2,0),B(n+2,0);
    while(q--){
        long long a,l,r;
        cin>>a>>l>>r;
        A[l] = (A[l]+a)%mod;
        A[r+1] =(A[r+1]- (a*powercalc(k,r-l+1)%mod)+mod)%mod;
    }


    vector<long long> prefA(n+1,0);
    long long cur=0;
    for(int i=1;i<=n;i++){
        cur = (cur*k)%mod;
        cur=(cur+A[i])%mod;
        prefA[i] = cur;
    }
    for(int i=1;i<=n;i++){
        cout<<prefA[i]<<" ";
    }
    cout<<endl;
    return 0;
}