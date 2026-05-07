#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> sz;

int findparent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}

void unite(int x, int y){
    int xparent=findparent(x);
    int yparent=findparent(y);
    if(xparent==yparent){
        return;
    }
    if(sz[xparent]<sz[yparent]){
        swap(xparent,yparent);
    }
    parent[yparent]=xparent;
    sz[xparent]+=sz[yparent];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int,int> mp;
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    parent.resize(n);
    sz.assign(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        if(mp.find(nums[i])==mp.end()){
            mp[nums[i]]=i;
        }
    }

    for(int i=0;i<n;i++){
        if(mp[nums[i]] != i){
            continue;
        }
        if(mp.find(nums[i]-1)!=mp.end()){
            unite(i,mp[nums[i]-1]);
        }
        if(mp.find(nums[i]+1)!=mp.end()){
            unite(i,mp[nums[i]+1]);
        }
    }
    int ans=1;
    for(int i=0;i<n;i++){
        if(findparent(i)==i){
            ans=max(ans,sz[i]);
        }
    }
    cout<<ans<<endl;
    

    return 0;
}
















/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109*/