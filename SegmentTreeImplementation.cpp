#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100100];
int tree[400400];

void build(int index, int l, int r){
    if(l==r){
        tree[index]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2 +1,mid+1,r);
    tree[index]=tree[2*index]+tree[2*index+1];
}

void update(int index, int l, int r, int pos, int v){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        tree[index]=v;
        arr[l]=v;
        return;
    }
    int mid=(l+r)/2;
    update(index*2,l,mid,pos,v);
    update(index*2+1,mid+1,r,pos,v);
    tree[index]=tree[index*2]+tree[index*2+1];
}

int query(int index, int l, int r, int lq, int rq){
    if(l>rq || r<lq){
        return 0;
    }
    if(lq<=l && rq>=r){
        return tree[index];
    }
    int mid=(l+r)/2;
    return query(index*2, l, mid, lq, rq)+query(index*2+1,mid+1,r,lq,rq);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int choice;
        cin>>choice;
        if(choice==1){
            int x,v;
            cin>>x>>v;
            update(1,0,n-1,x,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            query(1,0,n-1,l,r);
        }
    }
    return 0;
}