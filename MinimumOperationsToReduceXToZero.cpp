#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    int temp=sum-x;
    if(sum<x){
        cout<<-1<<endl;
        return 0;
    }
    if(sum==x){
        cout<<n<<endl;
        return 0;
    }
    int left=0,tempsum=0,length=INT_MIN;
    for(int right=0;right<n;right++){
        tempsum+=nums[right];
        while(tempsum>temp){
            tempsum-=nums[left];
            left++;
        }
        if(tempsum==temp){
            length=max(length,right-left+1);
        }
    }
    if(length<0){
        cout<<-1<<endl;
    }
    else{
        cout<<n-length<<endl;
    }
    return 0;
}