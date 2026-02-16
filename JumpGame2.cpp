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
    int jumps=0,currentpos=0,further=0;
    for(int i=0;i<n-1;i++){
        further=(max(further,i+nums[i]));
        if(i==currentpos){
            jumps++;
            currentpos=further;
        }
    }
    cout<<jumps<<endl;
    return 0;
}