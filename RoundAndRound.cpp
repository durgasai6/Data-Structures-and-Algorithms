#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x=0,y=0;
        bool north=true,south=false,west=false,east=false;
        int turns=4*9999;
        
        for(char c :s){
            if(c=='R'){
                turns++;
            }
            else if(c=='L'){
                turns--;
            }
            if(turns%4==0){
                north= true;
                south = east = west =false;
            }
            else if(turns%4==1){
                west = true;
                north=south=east=false;
            }
            else if(turns%4==2){
                south=true;
                north=west=east=false;
            }
            else if(turns%4==3){
                east = true;
                north = west=south=false;
            }
            if(c == 'W' && north){
                y++;
            }
            else if(c == 'W' && south){
                y--;
            }
            else if(c == 'W' && east){
                x--;
            }
            else if(c == 'W' && west){
                x++;
            }
        }
        if(x==0 && y==0 || !north){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}