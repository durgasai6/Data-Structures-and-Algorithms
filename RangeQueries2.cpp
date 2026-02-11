#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> segtree;

void update(int idx, int left, int right, int l, int r, long long value){
    if(left>r || right<l){
        return;
    }
    if(left>=l && right<=r){
        segtree[idx] +=value;
        return;
    }
    int mid = (left+right)/2;
    update(2*idx,left,mid,l,r,value);
    update(2*idx +1,mid+1,right,l,r,value);
}

long long secondtype(int idx, int left , int right, int position){
    if(position<left ||position>right){
        return 0;
    }
    if(left==right){
        return segtree[idx];
    }
    int mid=(left+right)/2;
    if(position<=mid){
        return segtree[idx]+ secondtype(2*idx, left, mid, position);
    }
    else{
        return segtree[idx]+ secondtype(2*idx +1, mid+1, right, position);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    a.resize(n+1);
    segtree.resize(4*n);

    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int i,j;
            long long x;
            cin>>i>>j>>x;
            update(1,1,n,i,j,x);
        }
        else{
            int i;
            cin>>i;
            cout<<a[i] + secondtype(1,1,n,i)<<endl;
        }
    }
    return 0;
}