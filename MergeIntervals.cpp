#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    for(int i=0;i<n;i++){
        cin>>points[i].first>>points[i].second;
    }

    sort(points.begin(),points.end());
    vector<pair<int,int>> answer;
    answer.push_back(points[0]);
    for(int i=1;i<n;i++){
        if(points[i].first<=answer.back().second){
            answer.back().second=max(answer.back().second, points[i].second);
        }
        else{
            answer.push_back(points[i]);
        }
    }
    for(int i=0;i<answer.size();i++){
        cout<<"{"<<answer[i].first<<","<<answer[i].second<<"}"<<endl;
    }
    return 0;
}




/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104*/