#include<bits/stdc++.h>
using namespace std;

int main(){
    int q,k;
    cin>>q>>k;
    multiset<long long> A,B;
    long long sumA=0;

    while(q--){
        int query;
        cin>>query;
        if(query ==1){
            long long x;
            cin>>x;
            if(A.size()<k){
                A.insert(x);
                sumA+=x;
            }
            else if(A.size()>=k){
                B.insert(x);
            }
        }
        else if(query == 2){
            int x;
            cin>>x;
            auto it = A.find(x);
            if(it !=A.end()){
                A.erase(it);
                sumA -=x;
                continue;
            }
            it = B.find(x);
            if(it != B.end()){
                B.erase(it);
            }
        }
        else if(query == 3){
            char ch;
            cin>>ch;
            cout<<sumA<<endl;
        }
    }
    return 0;
}