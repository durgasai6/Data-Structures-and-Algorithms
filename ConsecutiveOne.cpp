#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> A(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int zeroes=0;
        int l=0;
        int maxlength=0;
        for( int r=0;r<n;r++){
            if(A[r]==0){
                zeroes++;
            }
            while(zeroes>k){
                if(A[l] == 0){
                    zeroes--;
                }
                l++;
            }
            maxlength = max(maxlength, r-l+1);
        }
        cout<<maxlength<<endl;
        
    }
    return 0;
}

/*done using two pointer*/