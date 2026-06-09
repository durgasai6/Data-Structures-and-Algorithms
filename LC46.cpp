#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> curr;


void dfs( vector<int>& nums,vector<bool>& used){
    if(nums.size()==curr.size()){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]){
            continue;
        }
        used[i]=true;
        curr.push_back(nums[i]);
        dfs(nums,used);
        curr.pop_back();
        used[i]=false;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<bool> used(n,false);
    dfs(nums,used);
    for(int i=0;i<n;i++){
        int s=ans[i].size();
        for(int j=0;j<s;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}