#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            cout<<1<<endl;
        }
        else{
            long long D= b*b- 4*a*c;
            if(D>0){
                cout<<2<<endl;
            }
            else if(D==0){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}