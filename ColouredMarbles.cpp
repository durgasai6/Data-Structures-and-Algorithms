#include<bits/stdc++.h>
using namespace std;


const long long mod = 1000000007;
long long fact[100001];

int solve(int a, int b, int p){
    if(b==0){
        return 1;
    }
    
    int t= solve(a,b/2,p);
    t = (t*t)%p;
    if(b%2==1){
        return (a*t)%p;
    }
    return t;
}


int main (){
    fact[0] =1;
    for (int i=1;i <=100000;++i) {
    fact[i] = (fact[i-1] * i) % mod;
    }
    int t;
    cin>>t;
    while(t>0){
        int n,c1,c2,c3;
        cin>>n;
        cin>>c1;
        cin>>c2;
        cin>>c3;

        int result = fact[n];
        result = (result * solve(fact[c1],mod-2,mod))% mod;
        result = (result * solve(fact[c2],mod-2,mod))% mod;
        result = (result * solve(fact[c3],mod-2,mod))%mod;
        cout<<result<< "\n";
        t--;
        
    }



    


    return 0;
}