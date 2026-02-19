#include<bits/stdc++.h>
using namespace std;
int n,m;

void dfs(vector<vector<int>>& grid,int i, int j){
    if(i<0 || j<0 || i>=n ||j>=m || grid[i][j]==0){
        return;
    }
    grid[i][j]=0;
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                answer++;
                dfs(grid,i,j);
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}



/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.*/