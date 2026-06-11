#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin>>a>>b;
    int gcd=__gcd(a,b);
    int lcm=(a*b)/gcd;

    vector<bool> primes(b+1,true);
    primes[0]=false;
    if(b>=1){
        primes[1]=false;
    }

    for(int i=2;i*i<=b;i++){
        if(primes[i]){
            for(int j=i*i;j<=b;j+=i){
                primes[j]=false;
            }
        }
    }
    cout<<gcd<<" "<<lcm<<endl;
    for(int i=max(2,a);i<=b;i++){
        if(primes[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}