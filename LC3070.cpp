#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> prefix(n, vector<int>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                prefix[i][j]=grid[i][j];
                
            }
            if(i>0 && j==0){
                prefix[i][j]=prefix[i-1][j]+grid[i][j];
                
            }
            if(i==0 && j>0){
                prefix[i][j]=prefix[i][j-1]+grid[i][j];
                
            }
            if(i>0 && j>0){
                prefix[i][j]=grid[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
            if(prefix[i][j]<=k){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}








/*You are given a 0-indexed integer matrix grid and an integer k.

Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

 

Example 1:


Input: grid = [[7,6,3],[6,6,1]], k = 18
Output: 4
Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
Example 2:


Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
Output: 6
Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
 

Constraints:

m == grid.length 
n == grid[i].length
1 <= n, m <= 1000 
0 <= grid[i][j] <= 1000
1 <= k <= 109*/