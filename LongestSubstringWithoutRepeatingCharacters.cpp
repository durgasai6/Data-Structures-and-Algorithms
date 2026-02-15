#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> freq(130,0);
    int l=0, answer=0;
    for(int r=0;r<n;r++){
        freq[s[r]]++;
        while(freq[s[r]]>1){
            freq[s[l]]--;
            l++;
        }
        answer=max(answer,r-l+1);
    }
    cout<<answer<<endl;
    return 0;
}