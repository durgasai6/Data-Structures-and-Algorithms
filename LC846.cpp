#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    int n,groupSize;
    cin>>n>>groupSize;
    vector<int> hand(n);
    for(int i=0;i<n;i++){
        cin>>hand[i];
    }
    if(hand.size()%groupSize !=0){
        cout<<"false"<<endl;
        return 0;
    }
    sort(hand.begin(),hand.end());
    unordered_map<int,int> freq;
    for(int x:hand){
        freq[x]++;
    }
    for(int i=0;i<hand.size();i++){
        if(freq[hand[i]]==0){
            continue;
        }
        int curr=hand[i];
        for(int j=0;j<groupSize;j++){
            if(freq.find(curr+j)==freq.end() || freq[curr+j]==0){
                cout<<"false"<<endl;
                return 0;
            }
            freq[curr+j]--;
        }
    }
    cout<<"true"<<endl;
    return 0;
}











/*Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length*/