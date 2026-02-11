#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> prefix0(n+1,0),prefix1(n+1,0);
    long long answer =0;
    for(int i=1;i<=n;i++){
        prefix0[i] = prefix0[i-1];
        prefix1[i] = prefix1[i-1];
        if(a[i]==0){
            prefix0[i]++;
        }
        else{
            prefix1[i]++;
        }
    }
    long long y=1;
    while(y>=0){
        long long length=y*y + y;
        if (length>n){
            break;
        }
        for(int h=length;h<=n;h++){
            int l = h-length+1;
            int zeroes = prefix0[h] - prefix0[l-1];
            int ones = prefix1[h] - prefix1[l-1];
            if(zeroes==y && ones == y*y){
                answer++;
            }
        }
        y++;
    }
    cout<<answer<<endl;
    return 0;
}