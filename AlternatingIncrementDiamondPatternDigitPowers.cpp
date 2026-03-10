#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n%2==0){
        cout<<-1<<endl;
        return 0;
    }
    int x=3;
    int k=n;
    int last=3;
    int m=1;
    for(int i=1;i<(n*n)-(n*10);i++){
        last+=x+m;
        m+=2;
    }
    while(k>=0){
        for(int i=1;i<=n/2 +1;i++){
            for(int i=1;i<(n*n)-(n*10);i++){
                
            }
        }
        k-=2;
    }
    return 0;
}