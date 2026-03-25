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
    int idx=0,ops=0;
    while(idx<n-2){
        if(nums[idx]==0){
            nums[idx]=1;
            if(nums[idx+1]==0){
                nums[idx+1]=1;
            }
            else{
                nums[idx+1]=0;
            }
            if(nums[idx+2]==0){
                nums[idx+2]=1;
            }
            else{
                nums[idx+2]=0;
            }
            ops++;
        }
        idx++;
    }
    for(int i=n-1;i>=0;i--){
        if(nums[i]==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ops<<endl;
    return 0;
}