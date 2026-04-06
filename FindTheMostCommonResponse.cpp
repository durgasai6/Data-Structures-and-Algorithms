#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<string>> responses(n);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        responses[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>responses[i][j];
        }
    }
    unordered_map<string, int> freq;
    for(int i=0;i<n;i++){
        unordered_set<string> unique(responses[i].begin(),responses[i].end());
        for(auto &s: unique){
            freq[s]++;
        }
    }
    string ans="";
    int maxfreq=0;
    for(auto &it:freq){
        if(it.second>maxfreq){
            maxfreq=it.second;
            ans=it.first;
        }
        else if(it.second ==maxfreq){
            if(ans=="" || it.first<ans){
                ans=it.first;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}













/*You are given a 2D string array responses where each responses[i] is an array of strings representing survey responses from the ith day.

Return the most common response across all days after removing duplicate responses within each responses[i]. If there is a tie, return the lexicographically smallest response.

 

Example 1:

Input: responses = [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]

Output: "good"

Explanation:

After removing duplicates within each list, responses = [["good", "ok"], ["ok", "bad", "good"], ["good"], ["bad"]].
"good" appears 3 times, "ok" appears 2 times, and "bad" appears 2 times.
Return "good" because it has the highest frequency.
Example 2:

Input: responses = [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]

Output: "bad"

Explanation:

After removing duplicates within each list we have responses = [["good", "ok"], ["ok", "bad"], ["bad", "notsure"], ["great", "good"]].
"bad", "good", and "ok" each occur 2 times.
The output is "bad" because it is the lexicographically smallest amongst the words with the highest frequency.
 

Constraints:

1 <= responses.length <= 1000
1 <= responses[i].length <= 1000
1 <= responses[i][j].length <= 10
responses[i][j] consists of only lowercase English letters*/