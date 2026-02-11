#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<long long> size;

int findparent(int current){
    if(parent[current]==current){
        return current;
    }
    return parent[current] = findparent(parent[current]);
}

void unifying(int x, int y){
    int xparent,yparent;
    xparent=findparent(x);
    yparent=findparent(y);
    if(xparent==yparent){
        return;
    }
    if(size[xparent]<size[yparent]){
        swap(xparent,yparent);
    }
    parent[yparent]=xparent;
    size[xparent]+=size[yparent];

}

int main(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        unifying(a,b);
    }

    vector<long long> components;
    for(int i=1;i<=n;i++){
        if(parent[i]==i){
            components.push_back(size[i]);
        }
    }



    long long answer=0,temp=0;
    for(long long c:components){
        answer+=temp*c;
        temp+=c;
    }
    cout<<answer<<endl;
    return 0;
}