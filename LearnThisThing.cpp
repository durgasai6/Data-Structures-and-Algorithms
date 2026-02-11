#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        long long n;
        cin>>n;

        long long bits = __builtin_popcountll(n);
        long long odd = 1LL << bits;

        long long even = (n+1) - odd;

        cout<< even <<" "<<odd<<endl;

    }


    
    return 0;
}