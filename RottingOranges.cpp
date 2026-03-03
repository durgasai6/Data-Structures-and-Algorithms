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
    int fresh=0,minutes=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1){
                fresh++;
            }
        }
    }
    while(!q.empty()){
        int k=q.size();
        bool rot=false;
        for(int i=0;i<k;i++){
            int x=q.front().first;
            int y = q.front().second;
            q.pop();
            if(x<n-1 && grid[x+1][y]==1){
                grid[x+1][y]=2;
                fresh--;
                q.push({x+1,y});
                rot=true;
            }
            if(y<m-1 && grid[x][y+1]==1){
                grid[x][y+1]=2;
                fresh--;
                q.push({x,y+1});
                rot=true;
            }
            if(x>0 && grid[x-1][y]==1){
                grid[x-1][y]=2;
                fresh--;
                q.push({x-1,y});
                rot=true;
            }
            if(y>0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                fresh--;
                q.push({x,y-1});
                rot=true;
            }
        }
        if(rot){
            minutes++;
        }
    }
    if(fresh>0){
        cout<<-1<<endl;
    }
    else{
        cout<<minutes<<endl;;
    }


    return 0;
}





/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/