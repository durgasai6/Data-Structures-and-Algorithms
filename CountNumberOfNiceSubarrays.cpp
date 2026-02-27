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
    int left=0,odds=0,answer=0;
    for(int right=0;right<n;right++){
        if(nums[right]%2!=0){
            odds++;
        }
        while(odds>k){
            if(nums[left]%2!=0){
                odds--;
            }
            left++;
        }
        answer+=(right-left+1);
    }

    int low=0,odds2=0,answer2=0;
    for(int high=0;high<n;high++){
        if(nums[high]%2!=0){
            odds2++;
        }
        while(odds2>k-1){
            if(nums[low]%2!=0){
                odds2--;
            }
            low++;
        }
        answer2+=(high-low+1);
    }
    cout<<answer-answer2<<endl;
    return 0;
}




/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length*/