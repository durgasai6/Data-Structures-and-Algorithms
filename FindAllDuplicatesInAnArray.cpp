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
    vector<int> answer;
    for(int i=0;i<n;i++){
        int idx=abs(nums[i])-1;
        if(nums[idx]<0){
            answer.push_back(idx+1);
        }
        else{
            nums[idx]= -nums[idx];
        }
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    return 0;
}