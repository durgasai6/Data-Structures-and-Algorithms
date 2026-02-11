#include<bits/stdc++.h>
using namespace std;

bool isprime(long long a){
    if(a<=1){
        return false;
    }
    if(a<=3){
        return true;
    }
    if(a%2 == 0 || a%3 == 0){
        return false;
    }

    for(int i=5; i*i <=a; i+=6){
        if(a%i == 0|| a%(i+2) == 0){
            return false;
        }
    }
    return true;
}

int n;
vector<bool> used;
vector<int> cycle;
int ans = 0;

void backtrack(){
    if(cycle.size() == n){
        if(isprime(cycle.back()+cycle[0])){
            ans++;
        }
        return;
    }

    for(int i=2;i<=n;i++){
        if(used[i]){
            continue;
        }

        int end = cycle.back();

        if((end % 2) == (i%2)){
            continue;
        }
        if (!isprime(end + i)){
            continue;
        }
        used[i] = true;
        cycle.push_back(i);
        backtrack();
        cycle.pop_back();
        used[i] = false;
    }
}

int main(){

    cin>>n;

    used.assign(n + 1, false);
    cycle.push_back(1);
    used[1] = true;

    backtrack();

    cout<<ans<<endl;

    return 0;
}