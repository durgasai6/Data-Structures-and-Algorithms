#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(n<3){
        cout<<"false"<<endl;
        return 0;
    }
    int left=0,right=n-1;
    while(left<n-1 && right>=1 && nums[left]<nums[left+1] && nums[right]<nums[right-1]){
        left++;
        right--;
    }
    int peak=0;
    if(left <n-1 && nums[left]>nums[left+1]){
        peak=nums[left];
        while(right>=1 && right>=left && nums[right]<nums[right-1]){
            right--;
        }
        
    }
    else if(right>=1 && nums[right]>nums[right-1]){
        peak=nums[right];
        while(left<n-1 && left<=right && nums[left]<nums[left+1] ){
            left++;
        }
        
    }
    if(left==0 || right==0 || left==n-1 || right==n-1){
        cout<<"false"<<endl;
        return 0;
    }
    if(left==right){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}

/*Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]*/