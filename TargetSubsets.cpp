#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long x;
        cin>>n>>x;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int mid=n/2;

        vector<int> left,right;
        for(int i=0;i<mid;i++){
            left.push_back(nums[i]);
        }
        for(int i=mid;i<n;i++){
            right.push_back(nums[i]);
        }
        vector<long long> leftsum;
        leftsum.push_back(0);
        for(int i=0;i<left.size();i++){
            int current = leftsum.size();
            for(int j=0;j<current;j++){
                leftsum.push_back(leftsum[j] + left[j]);
            }
        }
        sort(leftsum.begin(),leftsum.end());
        vector<long long> rightsum;
        rightsum.push_back(0);
        for(int i=0;i<right.size();i++){
            int current = rightsum.size();
            for(int j=0;j<current;j++){
                rightsum.push_back(rightsum[j]+right[j]);
            }
        }
        sort(rightsum.begin(),rightsum.end());

        long long answer = 0;
        for(long long i=0;i<leftsum.size();i++){
            if(leftsum[i]>x){
                continue;
            }
            long long remaining = x-leftsum[i];
            long long count = upper_bound(rightsum.begin(),rightsum.end(),remaining) - rightsum.begin();
            answer +=count;
        }
        cout<<answer<<endl;
    }
    return 0;
}