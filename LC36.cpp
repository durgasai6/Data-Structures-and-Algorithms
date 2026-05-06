#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> board(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    vector<set<char>> row(9),col(9),box(9);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='.'){
                continue;
            }
            int currbox=(i/3)*3 + (j/3);
            if(row[i].count(board[i][j])){
                cout<<"false"<<endl;
                return 0;
            }
            if(col[j].count(board[i][j])){
                cout<<"false"<<endl;
                return 0;
            }
            if(box[currbox].count(board[i][j])){
                cout<<"false"<<endl;
                return 0;
            }
            row[i].insert(board[i][j]);
            col[j].insert(board[i][j]);
            box[currbox].insert(board[i][j]);
        }
    }
    cout<<"true"<<endl;
    return 0;
}