#include<bits/stdc++.h>
using namespace std;

string s;


bool visited[7][7];
int ans=0;

void dfs(int x, int y, int moves){
    if(moves == 48){
        if(x==6 && y==0){
            ans++;
            return;
        }
        return;
    }

    if(x==6 && y==0 && moves<48){
        return;
    }
    visited[x][y] =true;

    bool up = (x>0 && !visited[x-1][y]);
    bool down = (x<6 && !visited[x+1][y]);
    bool right = (y<6 && !visited[x][y+1]);
    bool left = (y>0 && !visited[x][y-1]);


    if((!up && !down && right && left) || (up && down && !right && !left)){
        visited[x][y] = false;
        return;
    }

    char c = s[moves];

    if(c == 'D' || c=='?'){
        int nextx = x+1;
        int nexty = y;
        if((nextx>=0 && nextx<7 && nexty>=0 && nexty<7) && !visited[nextx][nexty]){
            dfs(nextx, nexty, moves+1);
        }
    }
    if(c=='L' || c=='?'){
        int nextx = x;
        int nexty = y-1;
        if((nextx>=0 && nextx<7 && nexty>=0 && nexty<7) && !visited[nextx][nexty]){
            dfs(nextx, nexty, moves+1);
        }
    }


    if(c == 'R' || c == '?'){
        int nextx = x;
        int nexty= y+1;
        if((nextx>=0 && nextx<7 && nexty>=0 && nexty<7) && !visited[nextx][nexty]){
            dfs(nextx, nexty, moves+1);
        }
    }



    if(c == 'U' || c == '?'){
        int nextx = x-1;
        int nexty = y;
        if((nextx>=0 && nextx<7 && nexty>=0 && nexty<7) && !visited[nextx][nexty]){
            dfs(nextx, nexty, moves+1);
        }
    }
    visited[x][y] = false;

}

int main(){
    cin>>s;

    dfs(0,0,0);

    cout<<ans<<endl;

    
    return 0;
}