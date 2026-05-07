#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        if(grid[i][0]==1 && visited[i][0]==0){
            q.push({i,0});
            visited[i][0]=1;
        }

        if(grid[i][m-1] && visited[i][m-1]==0){
            q.push({i,m-1});
            visited[i][m-1]=1;
        }
    }

    for(int i=0;i<m;i++){
        if(grid[0][i]==1 && visited[0][i]==0){
            q.push({0,i});
            visited[0][i]=1;
        }

        if(grid[n-1][i]==1 && visited[n-1][i]==0){
            q.push({n-1,i});
            visited[n-1][i]=1;
        }
    }

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && visited[nx][ny]==0){
                visited[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && visited[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}











/*You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.*/