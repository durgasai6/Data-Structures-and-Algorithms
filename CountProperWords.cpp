#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

long long power(long long a,long long p){
    a=a%mod;
    long long result=1;
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
        long long n;
        cin>>n;
        long long totalstrings=power(26,n);
        long long vowels = power(5,n);
        long long consonants = power(21,n);

        long long answer = totalstrings;
        answer = (answer - vowels + mod)%mod;
        answer = (answer - consonants +mod)%mod;
        cout<<answer<<endl;
    }
    return 0;
}