#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int firstsum=0;
    for(int i=0;i<k;i++){
        firstsum+=nums[i];
    }
    int sum=firstsum,answer=0;
    for(int i=1;i<n;i++){
        sum-=nums[i-1];
        int next=(i+k-1)%n;
        sum+=nums[next];
        if(sum!=firstsum){
            int difference=firstsum-sum;
            nums[next]+=difference;
            answer+=abs(difference);
            sum+=difference;
        }
    }
    cout<<answer<<endl;
    return 0;
}