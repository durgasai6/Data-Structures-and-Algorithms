#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums){
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        if(dp[i]==0){
            continue;
        }
        for(int j=1;j<=nums[i] && i+j <n ; j++){
            dp[i+j]=1;
        }
    }
    if(dp[n-1]!=0){
        return true;
    }
    return false;
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

    if(canJump(nums)){
        cout<<"True"<<endl;
        return 0;
    }
    cout<<"false"<<endl;
    return 0;
}










/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105*/