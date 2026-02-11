#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long target;
        cin>>n>>target;
        vector<long long> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        int l,h;
        long long mindif=LLONG_MAX;
        for(int k=0;k<n-2;k++){
            l=k+1,h=n-1;
            while(l<h){
                long long current = nums[k] +nums[l] +nums[h];
                mindif = min(mindif,abs(current - target));
                if(current<target){
                    l++;
                }
                else if(current>target){
                    h--;
                }
                else{
                    mindif=0;
                    break;
                }
            }
            if(mindif==0){
                break;
            }

        }
        cout<<mindif<<endl;
    }
    return 0;
}

