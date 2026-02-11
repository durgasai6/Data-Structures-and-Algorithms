#include<bits/stdc++.h>
using namespace std;
const long long mod =1000000007;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> pref(n+1,vector<long long>(m+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            long long num;
            cin>>num;
            num = ((num%mod)+mod)%mod;
            pref[i][j] = (pref[i-1][j] + pref[i][j-1] -pref[i-1][j-1] + num)%mod;

            pref[i][j] = ((pref[i][j] % mod)+mod)%mod;
        }
    }

    while(q--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        long long answer = (pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1])%mod;
        answer = ((answer%mod)+mod)%mod;
        cout<<answer<<endl;
    }
    return 0;
}