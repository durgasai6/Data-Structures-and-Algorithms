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
    string s;
    cin>>s;
    int n=s.size();
    parent.resize(n);
    sz.assign(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int m;
    cin>>m;
    vector<vector<int>> pairs(m,vector<int>(2));

    for(int i=0;i<m;i++){
        cin>>pairs[i][0]>>pairs[i][1];
        unite(pairs[i][0],pairs[i][1]);
    }

    unordered_map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int root=findparent(i);
        mp[root].push_back(i);
    }
    string ans=s;
    for(auto &it:mp){
        vector<int> idx=it.second;
        string temp="";
        for(int i:idx){
            temp+=s[i];
        }
        sort(idx.begin(),idx.end());
        sort(temp.begin(),temp.end());
        for(int i=0;i<idx.size();i++){
            ans[idx[i]]=temp[i];
        }
    }
    cout<<ans;


    return 0;
}



















/*You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.*/