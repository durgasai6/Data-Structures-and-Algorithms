#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int temp=n;
    int ans=0;
    if(temp>0){
        while(temp>0){
            ans=ans*10;
            ans+=temp%10;
        
            temp/=10;
        }
    }
    else if(temp<0){
        temp=temp*-1;
            while(temp>0){
            ans=ans*10;
            ans+=temp%10;
        
            temp/=10;
        }
        ans=ans*-1;
    }
    else{
        cout<<0<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}