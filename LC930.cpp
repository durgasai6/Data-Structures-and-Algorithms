#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& nums, int goal){
    if(goal<0){
        return 0;
    }
    int n=nums.size();
    int ans=0;
    int left=0;
    int sum=0;
    for(int right=0;right<n;right++){
        sum+=nums[right];
        while(sum>goal){
            sum-=nums[left];
            left++;
        }

        ans+=right-left+1;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,goal;
    cin>>n>>goal;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    cout<<solve(nums,goal)-solve(nums,goal-1)<<endl;
    return 0;
}
















/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length*/