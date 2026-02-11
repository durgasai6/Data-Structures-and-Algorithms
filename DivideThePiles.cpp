#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<long long> piles(n);
        long long gcd;
        cin>>gcd;
        piles[0] == gcd;
        for(int i=1;i<n;i++){
            cin>>piles[i];
            gcd = __gcd(gcd,piles[i]);
            if(gcd==1){
                break;
            }
        }
        
        if(gcd==1){
            cout<<"NO"<<endl;
        }
        else if(gcd>=2){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}