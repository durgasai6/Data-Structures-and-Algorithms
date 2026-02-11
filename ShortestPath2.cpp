#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    const long long infinity = 1e18;
    vector<vector<long long>> distance(n+1,vector<long long>(n+1,infinity));
    for(int i=1;i<=n;i++){
        distance[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        distance[a][b] = min(distance[a][b],c);
        distance[b][a] = min(distance[b][a],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                distance[i][j]= min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(distance[a][b] == infinity){
            cout<<"-1"<<endl;
        }
        else{
            cout<<distance[a][b]<<endl;
        }
    }
    return 0;
}