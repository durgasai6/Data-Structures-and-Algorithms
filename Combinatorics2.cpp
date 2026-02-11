#include <bits/stdc++.h>
using namespace std;




long long lcm(long long a,long long b) {
    return a/__gcd(a,b)*b;
}

long long countGood(long long x, vector<int>& b) {
    int n = b.size();
    long long cnt=0;

    for (int mask=1;mask<(1<<n);mask++) {
        long long cur=1;

        for (int i=0;i<n;i++) {
            if (mask & (1<<i)) {
                cur=lcm(cur,b[i]);
            }
        }

        int bits=__builtin_popcount(mask);

        if (bits%2==1)
            cnt+=x/cur;
        else
            cnt-=x/cur;
    }






    return cnt;
}

int main() {
    int n;
    long long k;
    cin >>n>>k;

    vector<int> b(n);
    for (int i=0;i<n;i++) {
        cin >>b[i];
    }
    long long low=1, high=1e18;
    while (low < high) {
        long long mid=(low+high)/2;

        if(countGood(mid,b)>=k)
            high=mid;
        else
            low=mid+1;
}
    cout<<low<<"\n";







    return 0;
}
