#include<bits/stdc++.h>
using namespace std;

int main(){
    int h;
    cin>>h;
    int n=h*(h+1)/2;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool possible=true;
    sort(a.begin(),a.end());
    for(int row=0;row<h-1;row++){
        for(int col=0;col<=row;col++){
            int parent = row*(row+1)/2 +col;
            int left = (row+1)*(row+2)/2 +col;
            int right =left+1;
            if(!(a[parent]<a[left] && a[parent]<a[right])){
                possible=false;
                break;
            }
        }
        if(!possible){
            break;
        }
    }
    if(possible){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}