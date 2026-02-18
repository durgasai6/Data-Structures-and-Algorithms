#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> points(n);
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }
    priority_queue<pair<long long,pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        long long x=points[i].first;
        long long y=points[i].second;
        long long dist=x*x + y*y;
        pq.push({dist,{x,y}});
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        pq.pop();
        }
    return 0;
}




/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).*/