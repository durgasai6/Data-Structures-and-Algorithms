#include<bits/stdc++.h>
using namespace std;
vector<long long> fibonacci;


void build(){
    fibonacci.push_back(1);
    fibonacci.push_back(1);
    while(true){
        long long nextnum = fibonacci.back() + fibonacci[fibonacci.size()-2];
        if(nextnum > 1e9){
            break;
        }
        fibonacci.push_back(nextnum);
    }
}

int main(){
    build();
    int t;
    cin>>t;
    
    
    while(t--){
        long long k;
        cin>>k;
        int cnt =0;
        for(int i=fibonacci.size()-1;i>=0;i--){
            while(fibonacci[i]<=k){
                k-= fibonacci[i];
                cnt++;
            }
        }
        cout<<cnt<<endl;
    
    
}
    return 0;
}


/*you can take the largest fibonacci number greater than or equal to the number k and then subtract it from k..
then take the new k and repeat the same process till you reach zero and keep counting the moves for each time you reuce k*/