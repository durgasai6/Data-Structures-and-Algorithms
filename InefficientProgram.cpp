#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
const long long inv2 = (mod+1)/2;

long long solve(long long n, long long m ){
    long long q = n/m;
    long long r = n%m;

    long long block = ((m%mod)*((m-1)%mod))%mod;
    block= (block*inv2)%mod;

    long long TotalBlocks = (q*block)%mod;

    long long left_over = ((r%mod)*((r+1)%mod))%mod;
    left_over = (left_over*inv2)%mod;

    return (TotalBlocks + left_over)%mod;
}

int main(){
    int t;
    cin>>t;


    while(t--){
        long long L, R, M;
        cin>>L>>R>>M;

        long long ans = abs((solve(R, M)) - solve(L-1, M));
        if(ans<0){
            ans+=mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}