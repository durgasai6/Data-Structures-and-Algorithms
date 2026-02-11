#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> degree(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
    }
    int maxdegree=0;
    for(int i=1;i<=n;i++){

        maxdegree = max(maxdegree,degree[i]);
    }

    int answer=maxdegree+1;
    cout<<answer<<endl;
    return 0;
}