#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> A(n), B(m);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<m;i++){
            cin>>B[i];
        }
        map<long long, long long> present;
        for(int i=0;i<n;i++){
            present[A[i]]++;
        }
        for(int i=0;i<m;i++){
            if(present[B[i]]>0){
                cout<<"YES"<<endl;
                present[B[i]]++;
            }
            else{
                cout<<"NO"<<endl;
                present[B[i]]++;
            }
        }
    }
    return 0;
}