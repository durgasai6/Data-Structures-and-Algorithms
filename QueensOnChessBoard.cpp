#include<bits/stdc++.h>
using namespace std;

vector<string> board(8);
bool col[8], dia1[15], dia2[15];
int ans = 0;

void backtrack(int row){
    if(row == 8){
        ans++;
        return;
    }

    for(int c=0;c<8;c++){
        if(board[row][c] == '*'){
            continue;
        }
        if(col[c]){
            continue;
        }
        if(dia1[row-c+7]){
            continue;
        }
        if(dia2[row+c]){
            continue;
        }
        col[c] = dia1[row-c+7]=dia2[row+c]=true;
        backtrack(row+1);
        col[c] = dia1[row-c+7]=dia2[row+c]=false;
    }
}

int main(){
    
    for(int i=0;i<8;i++){
        cin>>board[i];
    }
    backtrack(0);

    cout<<ans<<endl;

    return 0;
}