#include<bits/stdc++.h>
using namespace std;

int N;
int ans=0;
vector<bool> col,dia1,dia2;
vector<vector<bool>> board;

bool knight(int row, int col){
    if(row-2>=0 && col -1>=0){
        if(board[row-2][col-1]){
            return false;
        }
    }
    if(row-2>=0 && col+1<N){
        if(board[row-2][col+1]){
            return false;
        }
    }
    if(row-1>=0 && col-2>=0){
        if(board[row-1][col-2]){
            return false;
        }
    }
    if(row-1>=0 && col+2<N){
        if(board[row-1][col+2]){
            return false;
        }
    }
    return true;
}

void backtrack(int row){
    if(row == N){
        ans++;
        return;
    }

    for(int c=0;c<N;c++){
        if(col[c] || dia1[row-c+N-1] || dia2[row+c] || !knight(row,c)){
            continue;
        }
        col[c] = dia1[row-c+N-1] = dia2[row+c] = board[row][c] =true;
        backtrack(row+1);
        col[c] = dia1[row-c+N-1] = dia2[row+c] = board[row][c] =false;
    }
}


int main(){
    cin>>N;
    col.assign(N,false);
    dia1.assign(2*N, false);
    dia2.assign(2*N, false);
    board.assign(N, vector<bool>(N, false));
    backtrack(0);

    cout<<ans<<endl;

    return 0;
}