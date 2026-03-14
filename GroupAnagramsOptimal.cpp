#include<bits/stdc++.h>
using namespace std;

bool prime(int x){
    if(x<2){
        return false;
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<long long> primes;
    int i=2;
    while(primes.size()<26){
        if(prime(i)){
            primes.push_back(i);
        }
        i++;
    }
    unordered_map<long long, vector<string>> mp;
    for(string a:s){
        long long temp=1;
        for(char f:a){
            temp= (temp)*primes[f-'a'];
        }
        mp[temp].push_back(a);
    }

    for(auto &it:mp){
        for(string g:it.second){
            cout<<g<<" ";
        }
        cout<<endl;
    }

    return 0;
}








/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.*/