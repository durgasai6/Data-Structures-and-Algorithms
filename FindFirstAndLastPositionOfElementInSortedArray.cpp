#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int low=0;
    int high=nums.size()-1;
    int answer=-888;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(nums[mid]==t){
            answer=mid;
            high=mid-1;
        }
        else if(nums[mid]<t){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    low=0,high=nums.size()-1;
    int answer2=-999;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(nums[mid]==t){
            answer2=mid;
            low=mid+1;
        }
        else if(nums[mid]<t){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<answer<<" "<<answer2<<endl;
    return 0;
}

/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109*/