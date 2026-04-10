#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int, int> freq;
    int sum=0;
    int left=0;
    int ans=INT_MAX;    
    for(int right=0;right<n;right++){
        freq[nums[right]]++;
        if(freq[nums[right]]==1){
            sum+=nums[right];
        }
        while(sum>=k){
            ans=min(ans, right-left+1);
            freq[nums[left]]--;
            if(freq[nums[left]]==0){
                sum-=nums[left];
                freq.erase(nums[left]);
            }
            left++;
        }
    }
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}












/*You are given an integer array nums and an integer k.

Return the minimum length of a subarray whose sum of the distinct values present in that subarray (each value counted once) is at least k. If no such subarray exists, return -1.

 

Example 1:

Input: nums = [2,2,3,1], k = 4

Output: 2

Explanation:

The subarray [2, 3] has distinct elements {2, 3} whose sum is 2 + 3 = 5, which is ​​​​​​​at least k = 4. Thus, the answer is 2.

Example 2:

Input: nums = [3,2,3,4], k = 5

Output: 2

Explanation:

The subarray [3, 2] has distinct elements {3, 2} whose sum is 3 + 2 = 5, which is ​​​​​​​at least k = 5. Thus, the answer is 2.

Example 3:

Input: nums = [5,5,4], k = 5

Output: 1

Explanation:

The subarray [5] has distinct elements {5} whose sum is 5, which is at least k = 5. Thus, the answer is 1.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 109*/