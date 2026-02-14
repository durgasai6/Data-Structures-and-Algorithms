#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(grid[c][d]=='#'){
            cout<<-1<<endl;
            continue;
        }
        vector<vector<int>> distance(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        q.push({a,b});
        distance[a][b]=0;
        
        while(!q.empty()){
            pair<int,int> p=q.front();
            int x=p.first;
            int y=p.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nextx=x+dx[i];
                int nexty=y+dy[i];
                if(nextx>=0 && nextx<n && nexty>=0 && nexty<m){
                    if(grid[nextx][nexty]=='.' && distance[nextx][nexty]==-1){
                        distance[nextx][nexty]=distance[x][y]+1;
                        q.push({nextx,nexty});
                    }
                }
            }
        }
        cout<<distance[c][d]<<endl;
    }
    return 0;
}