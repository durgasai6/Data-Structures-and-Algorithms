#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int,int> freq;
    int l=0,answer=0;
    for(int r=0;r<n;r++){
        freq[a[r]]++;
        while(freq[a[r]]>k){
            freq[a[l]]--;
            l++;
        }
        answer=max(answer,r-l+1);
    }
    cout<<answer<<endl;
    return 0;
}

/*You are given an array of integers nums and an integer k.
Find the length of the longest subarray such that:
No element appears more than k times inside the subarray.*/