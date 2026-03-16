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
    int left=0, right=n-1;
    int idx=n-1;
    vector<int> answer(n);
    while(left<=right){
        if((nums[left]*nums[left])<(nums[right]*nums[right])){
            answer[idx]=nums[right]*nums[right];
            right--;
            idx--;
        }
        else{
            answer[idx]=nums[left]*nums[left];
            left++;
            idx--;
        }
        
    }
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}




/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.*/