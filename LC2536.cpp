#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries){
    vector<vector<int>> matrix(n,vector<int>(n,0));
    int m=queries.size();
    for(int i=0;i<m;i++){
        int x1=queries[i][0];
        int y1=queries[i][1];
        int x2=queries[i][2];
        int y2=queries[i][3];

       
        matrix[x1][y1]++;
        
        if(x2+1<n && y2+1<n){
            matrix[x2+1][y2+1]++;
        }
        if(y2+1<n){
            matrix[x1][y2+1]--;
        }
        if(x2+1<n){
            matrix[x2+1][y1]--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>0){
                matrix[i][j]+=matrix[i-1][j];
            }
            if(j>0){
                matrix[i][j]+=matrix[i][j-1];
            }
            if(i>0 && j>0){
                matrix[i][j]-=matrix[i-1][j-1];
            }
        }
    }
    return matrix;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> queries(m,vector<int>(4));
    for(int i=0;i<m;i++){
        for(int j=0;j<4;j++){
            cin>>queries[i][j];
        }
    }
    vector<vector<int>> ans= rangeAddQueries(n,queries);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl; 
    }
    return 0;
}










/*You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.

You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:

Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
Return the matrix mat after performing every query.

 

Example 1:


Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
Output: [[1,1,0],[1,2,1],[0,1,1]]
Explanation: The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
- In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
- In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).
Example 2:


Input: n = 2, queries = [[0,0,1,1]]
Output: [[1,1],[1,1]]
Explanation: The diagram above shows the initial matrix and the matrix after the first query.
- In the first query we add 1 to every element in the matrix.
 

Constraints:

1 <= n <= 500
1 <= queries.length <= 104
0 <= row1i <= row2i < n
0 <= col1i <= col2i < n*/