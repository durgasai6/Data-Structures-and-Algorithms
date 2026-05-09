#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> vis;

long long dfs(vector<vector<int>>& grid, int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j]){
        return 0;
    }
    vis[i][j]=1;
    long long sum=grid[i][j];
    sum+=dfs(grid,i+1,j);
    sum+=dfs(grid,i-1,j);
    sum+=dfs(grid,i,j-1);
    sum+=dfs(grid,i,j+1);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vis.assign(n,vector<int>(m, 0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]>0 && !vis[i][j]){
                long long sum=dfs(grid,i,j);
                if(sum%k==0){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}











/*You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).

The total value of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value divisible by k.

 

Example 1:


Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

Output: 2

Explanation:

The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

Example 2:


Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

Output: 6

Explanation:

The grid contains six islands, each with a total value that is divisible by 3.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
0 <= grid[i][j] <= 106
1 <= k <= 106*/