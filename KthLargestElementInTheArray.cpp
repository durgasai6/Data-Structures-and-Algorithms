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
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    cout<<pq.top()<<endl;
    return 0;
}


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,k;
//     cin>>n>>k;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     priority_queue<int> pq;
//     for(int i=0;i<n;i++){
//         pq.push(nums[i]);
//     }
//     for(int i=0;i<k-1;i++){
//         pq.pop();
//     }
//     cout<<pq.top();
//     return 0;
// }




/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104*/