#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> dists(n+1,-1),distt(n+1,-1);
        queue<int> q;
        q.push(s);
        dists[s]=0;
        while(!q.empty()){
            int current=q.front();
            q.pop();
            for(int next: adj[current]){
                if(dists[next]==-1){
                    dists[next]=dists[current]+1;
                    q.push(next);
                }
            }
        }
        if(dists[t]==-1){
            cout<<-1<<endl;
            continue;
        }
        int answer=dists[t];
        int count=0;
        q.push(t);
        distt[t]=0;
        while(!q.empty()){
            int current=q.front();
            q.pop();
            for(int next:adj[current]){
                if(distt[next]==-1){
                    distt[next]=distt[current]+1;
                    q.push(next);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dists[i]+distt[i]==answer){
                count++;
            }
        }
        cout<<count<<endl;

    }
    return 0;
}