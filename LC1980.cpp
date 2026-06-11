#include<bits/stdc++.h>
using namespace std;

string binary(int x){
    if(x==0){
        return "0";
    }
    string bin="";
    while(x>0){
        bin+=(x%2)+'0';
        x=x/2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

int power(int a, int p){
    int res=1;
    while(p>0){
        if(p%2==1){
            res=res*a;
        }
        a=a*a;
        p=p/2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<string> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k=nums[0].size();
    int start=0;
    int end=power(2,k)-1;

    unordered_map<string,int> mp;
    for(string s:nums){
        mp[s]++;
    }
    for(int i=start;i<=end;i++){
        string temp=binary(i);
        while(temp.size()<k){
            temp='0'+temp;
        }
        if(mp.find(temp)==mp.end()){
            cout<<temp<<endl;
            return 0;
        }
    }
    return 0;
}
















/*Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.*/