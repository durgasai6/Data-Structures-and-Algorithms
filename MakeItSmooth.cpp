#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;

    while(t--){
        long long N;
        cin>>N;
        vector<long long> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        long long sum = 0;

        for(int i=1;i<N;i++){
            if(A[i]<A[i-1]){
                sum += A[i-1] - A[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}