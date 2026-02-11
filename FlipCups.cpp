#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int down=0;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='D'){
            down++;
        }
        
    }
    if(down%2==1){
            cout<<":("<<endl;
        }
    else if(down==2){
        cout<<":) 2"<<endl;
    }
    else{
        cout<<":) "<<down/2<<endl;
    }
    return 0;
}