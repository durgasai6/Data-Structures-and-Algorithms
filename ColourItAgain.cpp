#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

long long power(long long a, long long p){
    a=(a%mod);
    long long result=1;
    while(p>0){
        if(p%2!=0){
            result=(result*a)%mod;
        }
        a=(a*a)%mod;
        p/=2;
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        long long answer=1;
        if(k<=m && n>k){
            cout<<0<<endl;
            continue;
        }
        if(n<=m+1){
            for(int i=0;i<n;i++){
                long long temp=k-i;
                if(temp<=0){
                    answer=0;
                    break;
                }
                answer=(answer*temp)%mod;
            }
        }
        else{
            for(int i=0;i<=m;i++){
                long long temp=k-i;
                if(temp<=0){
                    answer=0;
                    break;
                }
                answer=(answer*temp)%mod;
            }
            if(answer!=0){
                long long remaining = n-(m+1);
                long long extra=power(k-m,remaining);
                answer=(answer*extra)%mod;
            }
        }
        cout<<answer<<endl;
        
    }
    return 0;
}