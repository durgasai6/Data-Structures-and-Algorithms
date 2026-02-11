#include<bits/stdc++.h>
using namespace std;
const long long maxi=1000000;
vector<long long> primes(maxi+1,1);

void sieve(){
    primes[0] = primes[1] =0;
    for(int i=2;i*i<=maxi;i++){
        if(primes[i]==1){
            for(int j=i*i;j<=maxi;j+=i){
                primes[j] =0;
            }
        }
    }
}

int main(){
    sieve();

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        if(primes[n]==1){
            cout<<"yes"<<endl;
            continue;
        }
        string s=to_string(n);
        int length = s.size();
        bool prime=false;

        for(int i=0;i<length && !prime ; i++){
            char old=s[i];
            for(char newchar = '0';newchar<='9';newchar++){
                if(newchar==old){
                    continue;
                }
                if(i==0 && newchar=='0'){
                    continue;
                }
                s[i]=newchar;
                int newnum=stoi(s);
                if(primes[newnum]==1){
                    prime=true;
                    break;
                }
            }
            s[i] = old;
        }
        if(prime){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"n0"<<endl;
        }
    }
    return 0;
}