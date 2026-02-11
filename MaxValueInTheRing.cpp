#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> diff(n+2,vector<long long>(m+2,0));
    while(q--){
        int x1,y1,x2,y2;long long c;
        cin>>x1>>y1>>x2>>y2>>c;
        diff[x1][y1] +=c;
        diff[x2+1][y1] -= c;
        diff[x1][y2+1] -= c;
        diff[x2+1][y2+1] += c;
    }
    long long maxi = -9999;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            diff[i][j] = diff[i][j] +diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            if(diff[i][j] >maxi){
                maxi = diff[i][j];
                cnt = 1;
            }else if(diff[i][j] == maxi){
                cnt++;
            }
        }
    }
    cout<<maxi<<" "<<cnt<<endl;
    return 0;
}