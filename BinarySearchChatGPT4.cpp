#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> bloomday(n);
    for(int i=0;i<n;i++){
        cin>>bloomday[i];
    }
    if((long long)m*k >n){
        cout<<-1<<endl;
    }
    int low=1;
    int high = *max_element(bloomday.begin(),bloomday.end());
    int ans=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int b=0,f=0;
        for(int i=0;i<n;i++){
            if(bloomday[i]<=mid){
                f++;
                if(f==k){
                    b++;
                    f=0;
                }
            }
            else{
                f=0;
            }
        }
        if(b>=m){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}


/*You are given an array bloomDay of size n.
bloomDay[i] = the day the i-th flower blooms
You want to make m bouquets
Each bouquet needs k adjacent flowers
A flower can be used only once
Return the minimum day on which you can make m bouquets.
If it’s impossible, return -1.


Input:
5 3 1
1 10 3 10 2

Output:
3*/