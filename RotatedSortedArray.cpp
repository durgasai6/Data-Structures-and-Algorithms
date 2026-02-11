#include<bits/stdc++.h>
using namespace std;

vector<long long> A;

long long binarysearch(long long l, long long h){
    if(l==h){
        return l;
    }
    long long mid = (l+h)/2;
    if(mid>0 && A[mid]<A[mid-1]){
        return mid;
    }
    else if(mid<h &&A[mid]>A[mid+1]){
        return mid+1;
    }
    else if(A[mid]>=A[l]){
        return binarysearch(mid+1,h);
    }
    else{
        return binarysearch(l,mid);
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        A.resize(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        cout<<binarysearch(0,n-1)<<endl;
    }
    return 0;
}