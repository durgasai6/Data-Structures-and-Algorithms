#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long answer=0;
        vector<int> initial=a;

        for(int i=31;i>=0;i--){
            vector<int> temp;
            for(int m : initial){
                if(m & (1LL<<i)){
                    temp.push_back(m);
                }
            }
            if(temp.size() >=x){
                answer = answer|(1LL<<i);
                initial=temp;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}