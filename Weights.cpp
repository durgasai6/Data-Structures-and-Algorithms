#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> weights(n);
        for(int i=0;i<n;i++){
            cin>>weights[i];
        }
        long long valid=0;

        sort(weights.begin(), weights.end());
        for(int i=0;i<n;i++){
            if(weights[i]>valid+1){
                break;
            }
            valid+=weights[i];
        }
        cout<<valid+1<<endl;
    }
    return 0;
}