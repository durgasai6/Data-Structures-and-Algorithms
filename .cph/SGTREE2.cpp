#include<bits/stdc++.h>
using namespace std;

const int size = 200000;
int t[4*size];

void build(int index, int l, int r){
    t[index] = 0;
    if(l==r){
        return;
    }
    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index +1, mid+1,r);
}

void update(int index, int l, int r, int ql, int qr, int val){
    if(r<ql || l>qr){
        return;
    }

    if(l>=ql && r<=qr){
        t[index] +=val;
        return;
    }


    int mid = (l+r)/2;
    update(index*2, l, mid, ql, qr, val);
    update(index*2 +1, mid +1, r, ql, qr, val);
}

int query(int index, int l , int r, int pos){
    if(l==r){
        return t[index];
    }
    int mid = (l+r)/2;

    if(pos<=mid){
        return t[index] + query(index*2, l, mid, pos);
    }
    else if(pos>mid){
        return t[index] + query(index*2 +1, mid+1, r, pos);
    }
    
}




int main(){
    int n, q;
    cin>>n;
    cin>>q;

    build(1,0,n-1);

    while(q>0){
        int quer;
        cin>>quer;
        
        if(quer == 1){
            int l,r,val;
            cin>>l;
            cin>>r;
            cin>>val;
            update(1,0,n-1,l,r,val);
        }
        else if(quer==2){
            int pos;
            cin>>pos;
            cout<<query(1,0,n-1,pos);
        }
        q--;
    }


    return 0;
}