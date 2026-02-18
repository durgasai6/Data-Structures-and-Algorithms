#include<bits/stdc++.h>
using namespace std;
int n;
const int maxi=2*100000 +5;
long long arr[maxi];
long long tree[maxi*4];

void build(int index, int l, int r){
    if(l==r){
        tree[index]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(index*2, l, mid);
    build(index*2+1,mid+1,r);
    tree[index]=tree[index*2]+tree[index*2+1];
}

void update(int index, int l, int r, int pos, int val){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        tree[index]=val;
        arr[l]=val;
        return;
    }
    int mid=(l+r)/2;
    update(index*2, l, mid, pos, val);
    update(index*2+1, mid+1, r, pos, val);
    tree[index]=tree[index*2]+tree[index*2+1];
}

long long  query(int index, int l, int r, int lq, int rq){
    if(lq>r || rq<l){
        return 0;
    }
    if(lq<=l && rq>=r){
        return tree[index];
    }
    int mid=(l+r)/2;
    return query(index*2,l,mid,lq,rq)+query(index*2+1, mid+1,r,lq,rq);
}

int main(){
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    
    for(int i=0;i<q;i++){
        int choice;
        cin>>choice;
        if(choice==1){
            int x,v;
            cin>>x>>v;
            update(1,0,n-1,x-1,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(1,0,n-1,l-1,r-1)<<endl;;
        }
    }

    return 0;
}