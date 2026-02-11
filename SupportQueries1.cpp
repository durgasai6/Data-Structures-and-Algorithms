#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    map<long long,long long> store;
    while(q--){
        int query;
        cin>>query;

        if(query == 1){
            long long x;
            cin>>x;
            store[x]++;
        }
        else if(query == 2){
            long long x;
            cin>>x;
            if(store[x] == 0){
                continue;
            }
            else if(store[x]>0){
                store[x]--;
                if(store[x]==0){
                    store.erase(x);
                }
            }
        }
        else if(query == 3){
                char ch;
                cin>>ch;
                if(store.empty()){
                    cout<<"-1"<<endl;
                }
                else{
                    cout<<store.begin()->first<<endl;;
                }
            }
            else if(query == 4){
                char ch;
                cin>>ch;
                if(store.empty()){
                    cout<<"-1"<<endl;
                }
                else{
                    cout<<store.rbegin()->first<<endl;;
                }
            }
            else if(query == 5){
                char ch;
                cin>> ch;
                if(store.empty()){
                    cout<<"0"<<endl;
                }
                else{
                    long long sum=0;
                    for(auto it : store){
                        sum+=it.first*it.second;
                    }
                    cout<<sum<<endl;
                }
            }
        
    }
    return 0;
}