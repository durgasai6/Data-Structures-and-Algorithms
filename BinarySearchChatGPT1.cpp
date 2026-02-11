#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int low= *max_element(nums.begin(),nums.end());
    int high=0;
    for(int i=0;i<n;i++){
        high+=nums[i];
    }
    int answer=high;
    while(low<=high){
        int mid= low +(high-low)/2;
        int sum=0,count=1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count++;
                sum=nums[i];
            }
        }
        if(count<=k){
            answer=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<answer<<endl;
    return 0;
}



/*You are given an array of n positive integers and an integer k.
You need to divide the array into k or fewer continuous subarrays such that the maximum subarray sum is as small as possible.
Return that minimum possible maximum sum.

Input:
n = 5, k = 3  
arr = [2, 4, 7, 3, 5]

Output:
8*/