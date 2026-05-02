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
    long long ans=0,diff=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                long long curr=(long long)nums[i-1]-nums[i];
                if(curr>diff){
                    ans+=curr-diff;
                    diff=curr;
                }
                nums[i]+=curr;
            }else{
                diff=0;
            }
        }
    for(int x:nums){
        cout<<x<<" ";
    }
    return 0;
}