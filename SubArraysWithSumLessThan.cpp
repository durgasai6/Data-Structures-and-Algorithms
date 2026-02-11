#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        long long count= 0;
        int l=0;
        long long sum=0;
        long long answer=0;

        for(int h=0;h<n;h++){
            sum+=nums[h];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            answer += (h - l +1);
        }
        cout<<answer<<endl;
    }
    return 0;
}


/*just use sliding window and keep increasing the answer as long as the nums[i] < k
*/