#include<bits/stdc++.h>
using namespace std;
vector<string> ans;

void solve(string curr, int open, int close, int n){
    if(curr.size()==2*n){
        ans.push_back(curr);
        return;
    }
    if(open<n){
        solve(curr+"(",open+1,close,n);
    }
    if(close<open){
        solve(curr+")",open,close+1,n);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    solve("",0,0,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}