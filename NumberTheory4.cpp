#include<bits/stdc++.h>
using namespace std;

int main(){
    long long L,R;
    cin>>L>>R;

    long long max = sqrt(R);

    vector<bool> ISprime(max+1,true);
    ISprime[0] = ISprime[1] = false;

    vector<long long> primes;
    for(long long i=2;i<= max;i++){
        if(ISprime[i]){
            primes.push_back(i);
            for(long long j=i*i;j<=max;i+=i){
                ISprime[j] = false;
            }
        }
    }

    vector<bool> segment(R - L +1, true);

    for(long long p:primes){
        long long start = max(p*p, ((L+p-1)/p)*p);
        for(long long j= start; j<= R; j+=p){
            segment[j-L] = false;
        }
    }

    if(L==0){
        if(R>=0){
            segment[0] = false;
        }
        if(R>=1){
            segment[1] = false;
        }
    }
    if(L==1){
        segment[0] = false;
    }

    vector<long long> result;
    for(long long i=0;i<R-L;i++){
        if(segment[i]){
            result.push_back(L+i);
        }
    }

    cout<<result.size()<<"\n";
    for(long long x:result){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}