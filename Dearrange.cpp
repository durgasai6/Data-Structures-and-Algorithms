#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int maxfreq=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            freq[x]++;
            maxfreq = max(maxfreq, freq[x]);
        }
        int score = min(n,2*(n-maxfreq));;
        cout<<score<<endl;

    }
    return 0;
}


/*take frequencies of the numbers in an unordered map... the maximum freq at first is 0
upon taking the input values keep updating the maxfrequency
you cannot change more than n poisitons
and if the max frequency of a number is maxfreq
then (n-maxfreq) is the frequency of all other numbers...you can swap all these other numbers with the max freq number 
and increase the score*/