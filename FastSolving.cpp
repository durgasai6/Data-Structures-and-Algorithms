#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<long long> R(n);
        for(int i=0;i<n;i++){
            cin>>R[i];
        }
        vector<long long> time;
        time.assign(n,1);
        for(int i=1;i<n;i++){
            if(R[i]>R[i-1]){
                time[i]= time[i-1] +1; 
            }
        }
        for(int i=n-2;i>=0;i--){
            if(R[i]>R[i+1]){
                time[i] = max(time[i],time[i+1]+1); 
            }
        }
        long long totaltime=0;
        for(int i=0;i<n;i++){
            totaltime+= time[i];
        }
        cout<<totaltime<<endl;
    }
    return 0;
}


/*compare the ratings of the adjacent problems
if current problem has rating more than previous problem
it should take more time than the previous problem
if current problem has rating more than the next problem
then it should have rating maximum of the current problem and next problem+1
*/