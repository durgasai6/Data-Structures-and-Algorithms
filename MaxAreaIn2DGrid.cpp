#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> pref(r+1,vector<int>(c+1,0));
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            pref[i][j] = grid[i-1][j-1]+pref[i-1][j]+pref[i][j-1] - pref[i-1][j-1];
        }
    }
    cin>>t;
    while(t--){
        int x,y;
        long long k;
        cin>>x>>y>>k;

        int dmax=min({x,y,r-1-x,c-1-y});
        int low=0, high=dmax,radius=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int x1=x-mid+1;
            int x2=x+mid+1;
            int y1=y-mid+1;
            int y2=y+mid+1;
            int blackcount=pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
            
            if(blackcount<=k){
                radius=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(radius==-1){
            cout<<0<<endl;
        }
        else{
            cout<<(2*radius+1)*(2*radius+1)<<endl;
        }
    }
    
    

    

    return 0;
}