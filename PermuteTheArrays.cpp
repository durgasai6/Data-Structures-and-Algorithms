#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        long long sum=0;
        vector<int> A(n);
        vector<int> B(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for(int i=0;i<n;i++){
            sum+= abs(A[i]- B[i] );
        }
        cout<<sum;
    }

    return 0;
}