#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int B=0;
        vector<int> res(n);
        
        
        for(int i=0;i<n;i++){
            pq.push(A[i]);
            
            while(!pq.empty() && pq.top()<=B){
                pq.pop();
            }
            if(pq.size()>=B+1){
                B++;
            }
            res[i] = B;
            
        }
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        

    }
    return 0;
}

/*using minimum priority queue to store the pages of books makes it easy..
read 1 book store its pages in pq
then 2nd book and store its pages in pq 
keep updating the min pages to be read count B*/