#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    int answer=0;
    int count=0;
    for(int r=l;r<n;r++){
        if(a[r]==0){
            count++;
        }
        while(count>k){
            if(a[l]==0){
                count--;
            }
            l++;
        }
        answer=max(answer,r-l+1);
    }
    cout<<answer<<endl;

    return 0;
}

/*Problem Statement
You are given a binary array A of size N (elements are 0 or 1) and an integer K.
You may flip at most K zeroes to ones.
Find the maximum length of a contiguous subarray that contains only 1s after at most K flips.

Input:
9 2
1 0 1 1 0 0 1 1 1
Output: 7*/