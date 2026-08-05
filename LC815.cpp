#include<bits/stdc++.h>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
    if(source==target){
        return 0;
    }

    int n=routes.size();
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int m=routes[i].size();
        for(int j=0;j<m;j++){
            mp[routes[i][j]].push_back(i);
        }
    }
    queue<int> q;
    q.push(source);
    int ans=0;

    unordered_set<int> stops;
    vector<bool> buses(n,false);
    stops.insert(source);
    while(!q.empty()){
        int sz=q.size();
        ans++;
        while(sz--){
            int stop=q.front();
            q.pop();

            for(int x:mp[stop]){
                if(buses[x]){
                    continue;
                }
                buses[x]=true;

                for(int y:routes[x]){
                    if(y==target){
                        return ans;
                    }
                    if(!stops.count(y)){
                        stops.insert(y);
                        q.push(y);
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> routes(n);
    for(int i=0;i<n;i++){
        int m;
        vector<int> temp(m);
        for(int i=0;i<m;i++){
            cin>>temp[i];
        }
        routes.push_back(temp);
    }

    int source, target;
    cin>>source>>target;
    cout<<numBusesToDestination(routes, source, target);

    return 0;   
}











/*You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
 

 

Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 105
All the values of routes[i] are unique.
sum(routes[i].length) <= 105
0 <= routes[i][j] < 106
0 <= source, target < 106*/