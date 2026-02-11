#include<bits/stdc++.h>
using namespace std;
const long long maxi=1e18;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<long long>> distance(n+1,vector<long long>(m+1,maxi));

    for(int i=1;i<=n;i++){
        distance[i][i] =0;
    }
    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        distance[u][v] = min(distance[u][v],w);
        //distance[v][u] = min(distance[v][u],w);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(distance[i][k]<maxi && distance[k][j]<maxi){
                    distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(distance[i][j]==maxi){
                cout<<"* ";
            }
            else{
                cout<<distance[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}