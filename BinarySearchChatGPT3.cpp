#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> piles(n);
    for(int i=0;i<n;i++){
        cin>>piles[i];
    }
    int h;
    cin>>h;
    int low=1;
    int high= *max_element(piles.begin(),piles.end());
    int answer=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        int hours=0;
        for(int i=0;i<n;i++){
            hours+=(piles[i]+mid-1)/mid;
        }
        if(hours<=h){
            answer = mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    cout<<answer<<endl;
    return 0;
}