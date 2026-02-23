#include<bits/stdc++.h>
using namespace std;

int n,m;
bool found=false;

void dfs(vector<vector<char>> &board, string &s, int i, int j, int index){
    
    if(found==true){
        return;
    }
    
    if(index==s.length()){
        found=true;
        return;
    }

    if(i<0 ||j< 0|| i>=n ||j>=m ||board[i][j]!=s[index]){
        return;
    }
    char temp=board[i][j];
    board[i][j]='$';
    dfs(board,s,i+1,j,index+1);
    dfs(board,s,i-1,j,index+1);
    dfs(board,s,i,j+1,index+1);
    dfs(board,s,i,j-1,index+1);
    board[i][j]=temp;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    vector<vector<char>> board(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==s[0]){
                dfs(board,s,i,j,0);
            }
        }
    }
    if(found==true){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}










/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.*/