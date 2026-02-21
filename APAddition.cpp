#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<long long> constantpart(n+2,0);
    vector<long long> variablepart(n+2,0);

    while(q--){
        long long a,d,l,r;
        cin>>a>>d>>l>>r;
        long long c= (a-(l*d)%mod + mod)%mod;
        constantpart[l]=(constantpart[l]+c)%mod;
        constantpart[r+1]=(constantpart[r+1]-c+mod)%mod;
        variablepart[l]=(variablepart[l]+d)%mod;
        variablepart[r+1]=(variablepart[r+1]-d+mod)%mod;
    }
    long long con=0,var=0;
    for(int i=1;i<=n;i++){
        con=(con+constantpart[i])%mod;
        var=(var+variablepart[i])%mod;

        long long answer=(con+i*var%mod)%mod;
        cout<<answer<<endl;
    }
    return 0;
}




/*Given an array of N integers and Q queries. Initially, all the elements of the array have value 0.

In each query 4 integers A, D, L, R is given, which means perform AP addition

Arr[L]+=A

Arr[L+1]+=A+D

Arr[L+2]+=A+2*D

Arr[L+3]+=A+3*D

.

.

.

.

Arr[R]+=A+(R-L)*D.

After performing all the operations. Print the final array % 10^9+7.

Input Format

The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next Q lines contain four space-separated integers A, D, L, R where 0<=A,D<=10^4, 1<=L<=R<=N.

Output Format

Print the N space-separated integer representing the final array %10^9+7.

Sample Input 1
 Copy

5 5
1 3 1 5
2 4 2 2
5 6 3 5
6 9 5 5
1 4 2 4
Sample Output 1
 Copy

1 7 17 30 36 */