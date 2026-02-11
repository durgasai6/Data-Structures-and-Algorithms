#include<bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long powcalc(long long a, long long power){
    long long result = 1;
    a%=mod;
    while(power>0){
        if(power%2!=0){
            result = (result*a)%mod;
        }
        a =(a*a)%mod;
        power/=2;
    }
    return result;
}

int main(){
    int n,q;
    long long k;
    cin>>n>>q>>k;
    long long invk = powcalc(k,mod-2);
    vector<long long> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        nums[i] = (nums[i]%mod +mod)%mod;
    }
    vector<long long> powk(n+1),invpowk(n+1);
    powk[0] = 1;
    invpowk[0] = 1;
    for(int i=1;i<=n;i++){
        powk[i] = (powk[i-1]*k)%mod;
        invpowk[i] = (invpowk[i-1]*invk)%mod;
    }
    vector<long long> pref(n+1);
    pref[0]=0;
    for(int i=1;i<=n;i++){
        long long temp = (nums[i]*powk[i])%mod;
        pref[i] = (pref[i-1]+temp)%mod;
    }

    while(q--){
        int l,r;
        cin>>l>>r;

        long long sum = (pref[r] - pref[l-1]+mod)%mod;
        long long answer = (sum*invpowk[l])%mod;
        cout<<answer<<endl;
    }
    return 0;
}

/*solve the given fucntion by writing it in genralized form and precompute the powers of k and inverse powers of k*/