#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int left=0,right=n-1,answer=0;
    while(left<n-1 && nums[left]<=nums[left+1]){
        left++;
    }
    while(right>0 &&nums[right]>=nums[right-1]){
        right--;
    }
    if(left==n-1 || right==0){
        cout<<0<<endl;
        return 0;
    }
    answer=min(n-left-1,right);
    int i=0,j=right;
    while(i<=left && j<n){
        if(nums[i]<=nums[j]){
            answer=min(answer,j-i-1);
            i++;
        }
        else{
            j++;
        }
    }
    cout<<answer<<endl;
    return 0;
}




/*Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].
Example 2:

Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
Example 3:

Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
 

Constraints:

1 <= arr.length <= 105
0 <= arr[i] <= 109*/