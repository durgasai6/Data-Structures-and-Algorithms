#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;

    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int layers=min(n,m)/2;
    for(int i=0;i<layers;i++){
        vector<int> nums;

        int top=i;
        int left=i;
        int right=m-i-1;
        int bottom=n-i-1;
        for(int j=left;j<=right;j++){
            nums.push_back(grid[top][j]);
        }

        for(int j=top+1;j<bottom;j++){
            nums.push_back(grid[j][right]);
        }
        
        for(int j=right;j>=left;j--){
            nums.push_back(grid[bottom][j]);
        }

        for(int j=bottom-1;j>top;j--){
            nums.push_back(grid[j][left]);
        }

        int len=nums.size();
        int rot=k%len;

        vector<int> rotated(len);
        for(int j=0;j<len;j++){
            rotated[j]=nums[(j+rot)%len];
        }

        int idx=0;

        for(int j=left;j<=right;j++){
            grid[top][j]=rotated[idx];
            idx++;
        }
        for(int j=top+1;j<bottom;j++){
            grid[j][right]=rotated[idx];
            idx++;
        }
        for(int j=right;j>=left;j--){
            grid[bottom][j]=rotated[idx];
            idx++;
        }
        for(int j=bottom-1;j>top;j--){
            grid[j][left]=rotated[idx];
            idx++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}














/*You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:



A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:


Return the matrix after applying k cyclic rotations to it.

 

Example 1:


Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]
Explanation: The figures above represent the grid at every state.
Example 2:


Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
Explanation: The figures above represent the grid at every state.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
Both m and n are even integers.
1 <= grid[i][j] <= 5000
1 <= k <= 109*/