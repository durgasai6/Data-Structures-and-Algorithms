#include<bits/stdc++.h>
using namespace std;
const int maxi=1000000;

int main(){
    int t;
    cin>>t;
    vector<int> divisors(maxi+1,0);
    for(int i=1;i<=maxi;i++){
        for(int j=i;j<=maxi;j+=i){
            divisors[j]++;
        }
    }
    vector<long long> pref(maxi+1,0);
    for(int i=0;i<maxi+1;i++){
        pref[i] = divisors[i]+pref[i-1];
    }
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<pref[r] - pref[l-1]<<endl;
    }
    return 0;
}