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
    unordered_map<int,int> freq,left;
    int target=0;
    int answer=INT_MAX;
    for(int i=0;i<n;i++){
        if(left.count(nums[i])==0){
            left[nums[i]]=i;
        }
        freq[nums[i]]++;
        if(freq[nums[i]]>target){
            target=freq[nums[i]];
            answer=i-left[nums[i]]+1;
        }
        else if(freq[nums[i]]==target){
            answer=min(answer, i-left[nums[i]]+1);
        }
    }
    cout<<answer<<endl;
    return 0;
}







/*Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 

Example 1:

Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 

Constraints:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.*/