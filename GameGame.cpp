#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000009;
const long long maxi=2000005;
long long factorials[maxi],inversefactorials[maxi];

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

void precompute(){
    factorials[0]=1;
    for(int i=1;i<maxi;i++){
        factorials[i]=(factorials[i-1]*i)%mod;
    }
    inversefactorials[maxi-1]=power(factorials[maxi-1],mod-2);
    for(int i=maxi-2;i>=0;i--){
        inversefactorials[i]=(inversefactorials[i+1]*(i+1))%mod;
    }
}

long long ncr(long long a, long long b){
    if(b<0 || a<b){
        return 0;
    }
    return (((factorials[a]*inversefactorials[b])%mod)*inversefactorials[a-b])%mod; 
}

int main(){
    precompute();
    int t;
    cin>>t;
    while(t--){
        long long a,x,y;
        cin>>a;
        cin>>x>>y;
        long long win=max(x,y);
        long long lose=min(x,y);

        if(win==a && lose<=a-2){
            cout<<ncr(a+lose-1,a-1)<<endl;
            continue;
        }
        else if(win>=a && lose>=a-1 && win-lose==2){
            long long deucepoints= win-a;
            long long beforedeuce=ncr(2*(a-1),a-1);
            long long afterdeuce = power(2,lose-(a-1));
            cout<<(afterdeuce*beforedeuce)%mod<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }

    return 0;
}