#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>> graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;

        graph[a].push_back({b,c});
    }
    vector<long long> distance(n+1,LLONG_MAX);
    distance[1] = 0;
    priority_queue<pair<long long, int>,vector<pair<long long,int>>, greater<pair<long long, int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        long long currentdistance = current.first;
        int currentcity = current.second;
        if(currentdistance>distance[currentcity]){
            continue;
        }
        for(auto road : graph[currentcity]){
            int nextcity = road.first;
            long long roaddcost = road.second;
            long long newdistance = currentdistance + roaddcost;
            if(newdistance<distance[nextcity]){
                distance[nextcity] = newdistance;
                pq.push({newdistance,nextcity});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
    return 0;
}