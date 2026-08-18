#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int i){
    if(i==nums.size()){
        for(int x:temp){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }

    temp.push_back(nums[i]);
    solve(nums,i+1,temp);

    temp.pop_back();
    solve(nums,i+1,temp);
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
    
    solve(nums,0);

    return 0;
}





