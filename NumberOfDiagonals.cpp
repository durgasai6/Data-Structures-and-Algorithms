#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long inv2 = (mod+1)/2;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        long long dia = ((n % mod)*((n-3)%mod))%mod;
        dia= (dia*inv2)%mod;
        cout<<dia<<endl;
    }
    return 0;
}