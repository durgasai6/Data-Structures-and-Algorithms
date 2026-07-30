#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2){
    vector<int> timestamps;
    for(auto &i:series1){
        timestamps.push_back(i[0]);
    }

    for(auto &i:series2){
        timestamps.push_back(i[0]);
    }
    sort(timestamps.begin(),timestamps.end());
    timestamps.erase(unique(timestamps.begin(), timestamps.end()), timestamps.end());
    vector<vector<int>> ans;

    int i=0,j=0;

    for(int x:timestamps){
        while(i<series1.size() && series1[i][0]<x){
            i++;
        }
        while(j<series2.size() && series2[j][0]<x){
            j++;
        }
        int val1=0,val2=0;
        if(i<series1.size()){
            val1=series1[i][1];
        }
        if(j<series2.size()){
            val2=series2[j][1];
        }
        ans.push_back({x,val1+val2});
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> series1(n,vector<int>(2)), series2(m,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>series1[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>series2[i][j];
        }
    }


    vector<vector<int>> ans=aggregateTimeSeries(series1,series2);
    int a=ans.size();
    for(int i=0;i<a;i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}













/*You are given two 2D integer arrays series1 and series2.

Each element in both series is of the form [timestamp, value], where:

timestamp is an integer representing the time.
value is an integer representing the value at that timestamp.
Each array is sorted in strictly increasing order of timestamp.

For any timestamp not present in a series, its value is taken from the next available timestamp in the same series if one exists. Otherwise, its value is considered 0.

The aggregated series is formed by summing the corresponding values from both series at every timestamp that appears in either series.

Return the aggregated series as a 2D integer array of [timestamp, summedValue] pairs, sorted in strictly increasing order of timestamp.

 

Example 1:

Input: series1 = [[1,3],[4,1]], series2 = [[2,2],[5,2]]

Output: [[1,5],[2,3],[4,3],[5,2]]

Explanation:

Timestamp	series1	series2	summedValue
1	3	2	5
2	1	2	3
4	1	2	3
5	0	2	2
Thus, the aggregated series is [[1, 5], [2, 3], [4, 3], [5, 2]].

Example 2:

Input: series1 = [[1,5],[3,1]], series2 = [[2,2]]

Output: [[1,7],[2,3],[3,1]]

Explanation:

Timestamp	series1	series2	summedValue
1	5	2	7
2	1	2	3
3	1	0	1
Thus, the aggregated series is [[1, 7], [2, 3], [3, 1]].

Example 3:

Input: series1 = [[1,5]], series2 = [[1000000000,2]]

Output: [[1,7],[1000000000,2]]

Explanation:

At timestamp 1, the next available value in series2 is 2 at timestamp 1000000000. At timestamp 1000000000, there is no later timestamp in series1, so its value is 0. Only timestamps that appear in at least one of the two series are included.

 

Constraints:

1 <= series1.length, series2.length <= 105
series1[i].length == series2[i].length == 2
1 <= series1[i][0], series2[i][0] <= 109
1 <= series1[i][1], series2[i][1] <= 109
Each series is sorted in strictly increasing order of timestamp.*/