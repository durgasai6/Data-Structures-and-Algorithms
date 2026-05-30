#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> houses(n),heaters(m);
    for(int i=0;i<n;i++){
        cin>>houses[i];
    }
    for(int i=0;i<m;i++){
        cin>>heaters[i];
    }
    sort(heaters.begin(),heaters.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=lower_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin();
        int left=INT_MAX,right=INT_MAX;
        if(idx<heaters.size()){
            right=heaters[idx]-houses[i];
        }
        if(idx>0){
            left=houses[i]-heaters[idx-1];
        }

        int nearest=min(left,right);
        ans=max(ans,nearest);
    }
    cout<<ans<<endl;
    return 0;
}








/*Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will be the same.

 

Example 1:

Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.
Example 3:

Input: houses = [1,5], heaters = [2]
Output: 3
 

Constraints:

1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109*/