#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> prefixsumvector(n+1,0);

    for(int i=1;i<n+1;i++){
        long long num;
        cin>>num;
        prefixsumvector[i] = (prefixsumvector[i-1] +num)%mod;
    }
    while(q--){
        int L,R;
        cin>>L>>R;
        long long answer = (prefixsumvector[R] - prefixsumvector[L-1] + mod)%mod;
        cout<<answer<<endl;
    }
    return 0;
}