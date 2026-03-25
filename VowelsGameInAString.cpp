#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=0;
    for(char c:s){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            n++;
        }
    }
    if(n>0){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}