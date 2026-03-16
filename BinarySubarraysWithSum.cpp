#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,goal;
    cin>>n>>goal;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int sum=0,answer=0,left=0;
    for(int right=0;right<n;right++){
        sum+=nums[right];
        while(sum>goal){
            sum-=nums[left];
            left++;
        }
        answer+=right-left+1;
        
    }
    int sum2=0,answer2=0,left2=0;
    for(int right=0;right<n;right++){
        sum2+=nums[right];
        while(sum2>goal-1){
            sum2-=nums[left2];
            left2++;
        }
        answer2+=right-left2+1;
        
    }
    cout<<answer-answer2<<endl;
    return 0;
}