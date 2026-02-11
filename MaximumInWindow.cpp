#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long> A(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }

        vector<long long> B;
        deque<int> de;
        
        for(int i=0;i<n;i++){
            if(!de.empty() && de.front() < i-k){
                de.pop_front();
            }
            while(!de.empty() && A[de.back()]<=A[i]){
                de.pop_back();
            }
            de.push_back(i);

            if(i>=k-1){
                B.push_back(A[de.front()]);
            }
        }
        for(int i=0;i<B.size();i++){
            cout<<B[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*instead of pushing values into dequeue you can push indices which can be handled easily*/