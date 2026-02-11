#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

bool primecheck(long long a){
    if(a<=1 ){
        return false;
    }
    if(a<=3){
        return true;
    }
    if(a%2==0 || a%3==0){
        return false;
    }
    for(int i=5;i*i<=a;i+=6){
        if((a%i)==0 || ((a+2)%i)==0){
            return false;
        }
    }
    return true;
}

long long exppower(long long a, long long p){
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

int main(){
    int t;
    cin>>t;
    while(t--){
    long long a;
    cin>>a;
    if(primecheck(a)==0){
        cout<<a<<" is not a prime number"<<endl;
    }
    else{
        cout<<a<<" is a prime number"<<endl;
    }
    }
    return 0;
}