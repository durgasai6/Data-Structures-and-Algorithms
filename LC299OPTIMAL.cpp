#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string secret, guess;
    cin>>secret>>guess;
    int bulls=0,cows=0;
    unordered_map<char,int> cnt;
    for(int i=0;i<secret.size();i++){
        if(secret[i]==guess[i]){
            bulls++;
        }else{
            if(cnt[guess[i]]>0){
                cows++;
            }
            if(cnt[secret[i]]<0){
                cows++;
            }
            cnt[secret[i]]++;
            cnt[guess[i]]--;
        }
    }
    cout<<to_string(bulls) + "A" + to_string(cows) + "B"<<endl;
    return 0;
}