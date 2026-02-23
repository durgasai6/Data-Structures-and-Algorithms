#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int left=0,right=n-1;
    while(left<=right){
        if(nums[left]+nums[right]==target){
            cout<<left+1<<" "<<right+1<<endl;
            return 0;
        }
        else if(nums[left]+nums[right] > target){
            right--;
        }
        else{
            left++;
        }
    }
    return 0;
}