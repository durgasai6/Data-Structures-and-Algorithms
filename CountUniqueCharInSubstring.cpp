#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        long long answer=0;
        for(char c = 'a'; c<='z';c++){
            vector<int> pos;
            int prev,next;
            for(int i=0;i<n;i++){
                if(s[i]==c){
                    pos.push_back(i);
                }
            }
            for(int i=0;i<pos.size();i++){
                int currentpos=pos[i];
                if(i==0){
                    prev=-1;
                }
                else{
                    prev=pos[i-1];
                }
                if(i==pos.size()-1){
                    next=n;
                }
                else{
                    next=pos[i+1];
                }
                answer+=1LL*(currentpos-prev)*(next-currentpos);
            }
        }
        cout<<answer<<endl;
    }

    return 0;
}





/*Description

Given a string S consisting of the lowercase 
character of length N. 
Score of a string is the number of unique 
characters present in the string( characters 
which are only present once in the string). 
Like score of "character" is 3 {h,t,e}.
Find the sum of the score of all substring of S.

Input Format
The first line contains T, the number of test cases (1<=T<=10).
The first line of each test case contains an integers N, size of the string, 1<=N<=10^5.
The second line of each test case contains a string S of length N.

Output Format
For each test case print the sum of the score of all substring of S in a newline.
Sample Input 1


5
2
ac
3
aac
5
abode
5
aaaaa
10
jdnbfjdhzw
Sample Output 1
 Copy

4
6
35
5
194
Note

For the 1st test case:
Substring and score = ("a",1), ("c",1) ("ac",2).
Total score = 4

For the 2nd test case:
Substring and score = ("a",1), ("aa",0), ("aac",1), ("a",1), ("ac",2), ("c",1).
Total score = 6*/