#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,y;
    cin>>n>>y;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int answer=0;
    for(int i=0;i<n;i++){
        answer  ^=a[i];
    }
    if(n%2==0){
        cout<<"0"<<endl;
    }
    int finalresult=0;
    for(int i=0;i<y;i++){
        if((answer &(1<<i))==0){
            finalresult =finalresult|(1<<i);
        }
    }
    cout<<finalresult<<endl;
    return 0;
}