#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        long long answer=0;
        long long atmostk=0;
        vector<int> freq(1000001,0);
        int distinct=0,l=0;
        for(int h=0;h<n;h++){
            if(freq[nums[h]] == 0){
                distinct++;
            }
            freq[nums[h]]++;

            while(distinct>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    distinct--;
                }
                l++;
            }
            atmostk+=(h-l+1);

        }
        long long atmostkminus1=0;
            if(k>0){
                vector<int> freq2(1000001,0);
                int distinct2=0;
                int l2=0;
                for(int h=0;h<n;h++){
                    if(freq2[nums[h]]==0){
                        distinct2++;
                    }
                    freq2[nums[h]]++;
                    while(distinct2>k-1){
                        freq2[nums[l2]]--;
                        if(freq2[nums[l2]]==0){
                            distinct2--;
                        }
                        l2++;
                    }
                    atmostkminus1 += (h-l2+1);
                }
            }
            answer = atmostk -atmostkminus1;

        cout<<answer<<endl;

    }
    return 0;
}

