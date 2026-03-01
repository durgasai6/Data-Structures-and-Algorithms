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
    vector<int> freq(250,0);
    for(int i=0;i<n;i++){
        freq[nums[i]+100]++;
    }
    int idx=0;
    for(int i=0;i<250;i++){
        if(freq[i]>0){
            nums[idx]=i-100;
            idx++;
        }
    }
    cout<<idx<<endl;
    for(int i=0;i<idx;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}




/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.*/