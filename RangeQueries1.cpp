#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> segmenttree;

void buildsegmenttree(int idx,int left,int right){
    if(left==right){
        segmenttree[idx] = a[left];
        return;
    }
    int mid = (left+right)/2;
    buildsegmenttree(2*idx,left,mid);
    buildsegmenttree(2*idx+1,mid+1,right);
    segmenttree[idx]=segmenttree[2*idx] + segmenttree[2*idx +1];
}

long long sum(int idx, int left, int right, int l, int r){
    if(right<l || left >r){
        return 0;
    }
    if(left>=l && right<= r){
        return segmenttree[idx];
    }

    int mid = (left +right)/2;
    long long leftsum = sum(2*idx,left,mid,l,r);
    long long rightsum = sum(2*idx+1,mid+1,right,l,r);
    return leftsum+rightsum;
}




void update(int idx,int left, int right,int index, long long value){
    if(left==right){
        segmenttree[idx]=value;
        return;
    }
    int mid = (left+right)/2;
    if(index<=mid){
        update(2*idx,left,mid,index,value);
    }
    else{
        update(2*idx+1,mid+1,right,index,value);
    }
    segmenttree[idx] = segmenttree[2*idx]+segmenttree[2*idx+1];
}

int main(){
    int n,q;
    cin>>n>>q;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    segmenttree.resize(4*n);
    buildsegmenttree(1,1,n);
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int i;
            long long x;
            cin>>i>>x;
            update(1,1,n,i,x);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<sum(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}