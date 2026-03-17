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
    int left=0,zeros=0,len=0;
    for(int right=0;right<n;right++){
        if(nums[right]==0){
            zeros++;
        }
        while(zeros>1){
            if(nums[left]==0){
                zeros--;
            }
            left++;
        }
        len=max(len,right-left+1);
    }
    cout<<len-1<<endl;
    return 0;
}