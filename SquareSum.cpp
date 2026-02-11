#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        long long sum=0;
        vector<long long> A(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
            sum+=A[i];
        }

        long long avg = sum/n;
        long long avg2 = avg +1;

        long long answer =0;
        long long answer2=0;
        for(int i=0;i<n;i++){
            answer+= abs(A[i] - avg)*(abs(A[i] - avg));
            answer2+= abs(A[i] - avg2)*(abs(A[i] - avg2));
        }
        cout<<min(answer,answer2)<<endl;
    }
    return 0;
}