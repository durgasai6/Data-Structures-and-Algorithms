#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long l,r;
    cin>>l>>r;
    long long limit=sqrt(r);
    vector<bool> isprime(limit+1,true);
    isprime[0]=isprime[1]=false;
    for(long long i=2;i*i<=limit;i++){
        if(isprime[i]){
            for(long long j=i*i;j<=limit;j+=i){
                isprime[j]=false;
            }
        }
    }
    vector<long long> primes;
    for(long long i=0;i<=limit;i++){
        if(isprime[i]){
            primes.push_back(i);
        }
    }

    vector<bool> temp(r-l+1,true);
    for(long long p:primes){
        long long first = ((l+ p-1)/p)*p;
        first=max(first,p*p);
        for(long long j=first;j<=r;j+=p){
            temp[j-l]=false;
        }
    }
    if(l == 1){
        temp[0]=false;
    }
    vector<long long> answer;
    for(long long i=0;i<temp.size();i++){
        if(temp[i]==true){
            answer.push_back(l+i);
        }
    }
    
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    
    return 0;
}