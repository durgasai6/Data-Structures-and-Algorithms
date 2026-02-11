#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<long long, long long>> segments(n);
        vector<long long> part(n);
        long long answer=0;
        long long totalparts=0;
        for(int i=0;i<n;i++){
            cin>>segments[i].first>>segments[i].second;
        }
        sort(segments.begin(),segments.end());
        long long l=segments[0].first;
        long long r=segments[0].second;
        part[0]=0;
        for(int i=1;i<n;i++){
            if(segments[i].first<=r){
                r=max(r,segments[i].second);
                part[i]=totalparts;
            }
            else{
                totalparts++;
                l=segments[i].first;
                r=segments[i].second;
                part[i]=totalparts;
            }
        }
        totalparts++;
        for(int i=0;i<n;i++){
            long long currentpart=totalparts;

            bool left=(i>0 && part[i] ==part[i-1]);
            bool right=(i<n-1 && part[i] == part[i+1]);
            if(!left &&!right){
                currentpart--;
            }
            else if(left && right){
                continue;
            }
            else{
                if(i>0 && i<n-1){
                    if(segments[i-1].second < segments[i+1].first){
                        currentpart++;
                    }
                }
            }
            answer=max(answer,currentpart);
        }
        cout<<answer<<endl;
    }
    return 0;
}