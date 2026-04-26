#include<bits/stdc++.h>
using namespace std;

int dfs(int x, int y, vector<vector<int>> &grid){
    int m=grid.size();
    int n=grid[0].size();
    if(x<0 || x>m-1 || y<0 || y>n-1 || grid[x][y]==0){
        return 0;
    }
    grid[x][y]=0;
    int area=1;
    area+=dfs(x+1,y,grid);
    area+=dfs(x-1,y,grid);
    area+=dfs(x,y+1,grid);
    area+=dfs(x,y-1,grid);

    return area;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                int current=dfs(i,j,grid);
                ans=max(ans,current);
            }
        }
    }
    cout<<ans<<endl; 
    return 0;
}











/*You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.*/