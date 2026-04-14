#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    vector<vector<int>> arrays(m);
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            arrays[i].push_back(x);
        }
    }
    int mini=arrays[0][0],maxi=arrays[0][arrays[0].size()-1];
    
    int ans=0;
    for(int i=1;i<arrays.size();i++){
        int curmin=arrays[i][0];
        int curmax=arrays[i][arrays[i].size()-1];

        ans=max(ans, abs(curmax-mini));
        ans=max(ans,abs(maxi-curmin));
        mini=min(mini,curmin);
        maxi=max(maxi,curmax);
    }
    cout<<ans<<endl;
    return 0;
}















/*You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
 

Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.*/