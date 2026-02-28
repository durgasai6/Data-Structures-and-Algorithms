#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> bloomday(n);
    for(int i=0;i<n;i++){
        cin>>bloomday[i];
    }
    if(m*k>n){
        return -1;
    }
    int low=*min_element(bloomday.begin(),bloomday.end());
    int high=*max_element(bloomday.begin(),bloomday.end());
    while(low<high){
        int mid=low+(high-low)/2;
        int bouquets=0,flowers=0;
        for(int i=0;i<n;i++){
            if(bloomday[i]<=mid){
                flowers++;
                if(flowers==k){
                    bouquets++;
                    flowers=0;
                }
            }
            else{
                flowers=0;
            }
        }
        if(bouquets>=m){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<<low<<endl;
    return 0;
}