#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> stalls(n);
    for(int i=0;i<n;i++){
        cin>>stalls[i];
    }
    int c;
    cin>>c;
    
    int low= 1;
    int high= stalls[n-1]-stalls[0];
    int answer=0;
    while(low<=high){
        int mid= low+(high-low)/2;
        int cows=1;
        int lastcow=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-lastcow>= mid){
                cows++;
                lastcow =stalls[i];
            }
            
        }
        if(cows>=c){
            answer=mid;
            low=mid+1;   
        }
        else{
            high=mid-1;
        }
    }
    cout<<answer<<endl;
    return 0;
}

/*You are given n stall positions on a number line and c cows.
Place the cows in stalls such that the minimum distance between any two cows is as large as possible.
Return that maximum minimum distance.

Input:
stalls = [1, 2, 4, 8, 9]  
c = 3


Output:
3*/