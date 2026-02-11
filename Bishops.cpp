#include<bits/stdc++.h>
using namespace std;

int N,K;
int ans=0;
vector<bool> dia1, dia2;
vector<vector<bool>> board;

void backtrack(int index, int placed){
    if( placed == K){
        ans++;
        return;
    }
    if(index == N*N){
        return;
    }
    if(N*N - index < K - placed){
        return;
    }
    int row = index/N;
    int col = index%N;
    if(!dia1[row-col+N-1] && !dia2[row+col]){
        board[row][col] =dia1[row - col +N-1] =dia2[row+col] = true;
        backtrack(index+1, placed+1);
        board[row][col] =dia1[row - col +N-1] =dia2[row+col] = false;
    }
    backtrack(index+1, placed);
    
    
}

int main(){
    int T;
    cin>>T;
    while(T--){
    cin>>N>>K;

    ans=0;

    dia1.assign(2*N, false);
    dia2.assign(2*N, false);
    board.assign(N, vector<bool>(N, false));

    
    backtrack(0,0);
    
    cout<<ans<<endl;
    }

    return 0;
}