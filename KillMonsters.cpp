#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        long long soldiersleft=0;
        long long required = 0;
        vector<long long> A(n),B(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
        }
        multimap<long long, int, greater<int>> C;
        for(int i=0;i<n;i++){
            C.insert({A[i]-B[i],i});
        }
        for(auto &c :C){
            int x = c.second;

            if(soldiersleft< A[x]){
                required += (A[x] - soldiersleft);
                soldiersleft = A[x];
            }
            soldiersleft -= B[x];
        }
        cout<<required<<endl;
    }
    return 0;
}


/*For each monster, we need at least Ai soldiers before fighting it, and after the fight Bi soldiers are killed.
So if we start a fight with exactly Ai soldiers, we will be left with Ai − Bi soldiers after that battle.
Therefore, we fight the monsters in descending order of (Ai − Bi) — the monsters after which we retain more soldiers are fought earlier.*/