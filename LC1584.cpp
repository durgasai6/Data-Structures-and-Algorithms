#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>points[i][j];
        }
    }
    vector<int> mindist(n,INT_MAX);
    vector<bool> visited(n,false);
    mindist[0]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int u=-1;

        for(int j=0;j<n;j++){
            if(!visited[j] && (u==-1 || mindist[j]<mindist[u])){
                u=j;
            }
        }
        visited[u]=true;
        ans+=mindist[u];
        for(int k=0;k<n;k++){
            if(visited[k]){
                continue;
            }
            int cost=abs(points[u][0] - points[k][0])+abs(points[u][1]-points[k][1]);
            mindist[k]=min(mindist[k],cost);
        }
    }
    
    cout<<ans<<endl;


    return 0;
}













/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.*/