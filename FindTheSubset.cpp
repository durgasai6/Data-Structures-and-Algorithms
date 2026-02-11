#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        vector<bool> seen(n,false);
        long long pref=0;
        bool found = false;

        for(int i=0;i<n;i++){
            pref += nums[i];
            int remainder = pref % n;

            if(remainder==0){
                found = true;
                break;
            }
            if(seen[remainder]){
                found = true;
                break;
            }
            seen[remainder]= true;
        }
        cout<<(found ? "YES\n" : "NO\n");
    }
    return 0;
}

/*the answer is always YES
use pegion hole principle*/