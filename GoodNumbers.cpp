#include<bits/stdc++.h>
using namespace std;
const int maxi = 1000000;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> difference(maxi+2,0);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        difference[l]+=1;
        difference[r+1] -=1;
    }

    vector<int> ans(maxi+1,0);
    int current =0;

    for(int i=1;i<=maxi;i++){
        current +=difference[i];
        if(current>=k){
            ans[i] = 1;
        }
    }
    vector<int> pref(maxi+1,0);
    for(int i=1;i<=maxi;i++){
        pref[i] = pref[i-1] + ans[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pref[r] - pref[l-1]<<endl;
    }
    return 0;
}


/*difference array is the key*/