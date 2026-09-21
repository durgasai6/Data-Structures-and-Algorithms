#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    vector<pair<char,int>> freq;
    for(char c:s){
        mp[c]++;
    }

    for(auto &it:mp){
        freq.push_back({it.first,it.second});
    }

    sort(freq.begin(),freq.end(),[](pair<char,int> &a, pair<char,int> &b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    });
    
    int highest=freq[0].second;
    int second=-1;
    int index=0;

    for(int i=0;i<freq.size();i++){
        if(freq[i].second<highest){
            second=freq[i].second;
            index=i;
            break;
        }
    }

    if(second==-1){
        cout<<-1<<endl;
        return 0;
    }

    cout<<freq[index].first;

    
    
    return 0;
}















/*Given a non-empty string, find out the character that has second-highest frequency of occurrence in the string.

If there are no such characters, print -1

If there are multiple such characters, print the lexicographically smallest of them. ( As per their ASCII value)

Input
First line contains a single integer corresponding to integer N. ( Size of string )

Second line contains N-sized string.

Constraints

1≤N≤1000000

The characters in the string could be any valid ASCII character.

Output
A single character having the second-highest frequency and lexicographically smallest if there are multiple characters of the same frequency.

Examples
Input
aaaaaa
Output
-1
Input
nkslanfaaboutcec
Output
c
Input
`SgkEBzNnH
Output
-1*/