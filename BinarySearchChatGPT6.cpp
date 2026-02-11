#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int low= *min_element(a.begin(),a.end());
    int high = *max_element(a.begin(),a.end());
    int answer=high;

    while(low<=high){
        int mid=low + (high-low)/2;
        int pairs=0,count=0;
        for(int i=0;i<n;i++){
            if(a[i]<=mid){
                count++;
            }
            else{
                pairs+=count/2;
                count=0;
            }
        }
        pairs+=count/2;
        if(pairs>=k){
            answer=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<answer<<endl;
    return 0;
}

/*You are given an array a of size n and an integer k.
In one day, you can choose any index i and remove a[i].
After removals, the remaining array compresses.

Your goal:
Create at least k adjacent pairs where both elements in the pair are ≤ X.
Find the minimum X such that this is possible.*/