#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> flips(n+1,0);
    int count=0;

    for(int i=0;i<n;i++){
        if(i>0){
            flips[i]+=flips[i-1];
        }
        int current=(nums[i]+flips[i])%2;
        if(current%2==0){
            if(i+k>n){
                cout<<-1<<endl;
                return 0;
            }
            count++;
            flips[i]++;
            flips[i+k]--;
        }
        
    }
    cout<<count<<endl;
    return 0;
}