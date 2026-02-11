#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> houses(n),heaters(m);
    for(int i=0;i<n;i++){
        cin>>houses[i];
    }
    for(int i=0;i<m;i++){
        cin>>heaters[i];
    }
    int low=0,high=1e9,answer=high;
    while(low<=high){
        int mid= low + (high-low)/2;
        bool possible=true;
        int house=0, heater=0;
        while(house<n &&heater <m){
            if(abs(houses[house] - heaters[heater]<=mid)){
                house++;
            }
            else if(heaters[heater]< houses[house]){
                heater++;
            }
            else{
                possible=false;
                break;
            }
        }
        if(house<n){
            possible=false;
        }
        if(possible){
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


/*You are given positions of n houses and m heaters on a number line.
Each heater can warm houses within distance R.
Find the minimum radius R such that every house is covered by at least one heater.


houses  = [1, 5, 9]
heaters = [2, 8]
Output = 1*/