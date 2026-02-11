#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long flips=0;
        vector<int> bulbs(n);
        for(int i=0;i<n;i++){
            cin>>bulbs[i];
        }
        long long off=0;
        if(k==0){
            for(int i=0;i<n;i++){
                if(bulbs[i] == 0){
                    off++;
                }
                else{
                    continue;
                }
            }
            if(off>0){
                cout<<"-1"<<endl;
                off=0;
            }
        }
        vector<int> end(n+1,0);
        for(int i=0;i+k-1<n;i++){
            off+= end[i];
            int current = bulbs[i];

            if(off%2 != 0){
                current = 1 - current;
            }
            if(current == 0){
                flips++;
                off++;
                end[i+k]--;
            }

            for(int i=i-k;i<n;i++){
                off+=end[i];
                int current = bulbs[i];
                if(off%2 !=0){
                    current = 1-current;
                }
                if(current == 0){
                    cout<<"-1"<<endl;
                    break;
                }
            }
        }
        
        cout<<flips<<endl;
    }
    return 0;
}


/*instead of flipping k no. of bulbs every single time you come across an off bulb
you can keep track of how many times a bulb is getting affected..
if its even, then no need to change that bulb.. if its odd then it should be flipped*/