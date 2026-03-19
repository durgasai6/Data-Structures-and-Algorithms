#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int left=0,right=n-1;
    int index=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==x){
            index=mid;
            break;
        }
        else if(nums[mid]<x){
            index=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    int l=index,r=index+1;
    deque<int> ans;
    while(k--){
        if(l<0){
            ans.push_back(nums[r]);
            r++;
        }
        else if(r>=n){
            ans.push_front(nums[l]);
            l--;
        }
        else{
            if(abs(nums[l]-x)<=abs(nums[r]-x)){
                ans.push_front(nums[l]);
                l--;
            }
            else{
                ans.push_back(nums[r]);
                r++;
            }
        }
    }
    for(auto a : ans){
        cout<<a<<" ";
    }
    return 0;
}










/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]

 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104*/