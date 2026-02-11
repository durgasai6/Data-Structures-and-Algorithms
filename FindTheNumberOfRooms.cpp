#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string> grid;
vector<vector<bool>> visited;

void dfs(int x,int y){
    visited[x][y] = true;
    bool up =(x>0 && !visited[x-1][y] && grid[x-1][y]=='.');
    bool down = (x<n-1 && !visited[x+1][y] && grid[x+1][y]=='.');
    bool right = (y<m-1 && !visited[x][y+1] && grid[x][y+1]=='.');
    bool left  = (y>0 & !visited[x][y-1] && grid[x][y-1]=='.');

    if(up){
        dfs(x+1,y);
    }
    if(down){
        dfs(x+1,y);
    }
    if(right){
        dfs(x,y+1);
    }
    if(left){
        dfs(x,y-1);
    }

}

int main(){
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    visited.assign(n,vector<bool>(m,false));
    int rooms= 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                rooms++;
                dfs(i,j);
            }
        }
    }
    cout<<rooms<<endl;
    return 0;
}