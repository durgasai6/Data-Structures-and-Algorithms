#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin,s);
    int n=s.size();
    for(char c:s){
        if(c >='a' && c<='z'){
            cout<<c-'a'+1<<" ";
        }
        else if(c>='A' && c<='Z'){
            cout<<c-'A'+27<<" ";
        }
        else if(c==' '){
            cout<<0<<" ";
        }
        else if(c=='.'){
            cout<<99<<" ";
        }
    }
    
    return 0;
}









/*Problem Statement – Lexical Analyzer Encryption Challenge
For hiring by: GE Healthcare
Year Asked: 2022
Round: 1
Difficulty: Medium
Company Type: Super Dream
You are given the following paragraph of text:
“COVID crisis has taught us several lessons and together we have overcome this great challenge. The COVID pandemic sent shock waves through the world economy and triggered the largest global economic crisis in more than a century. The crisis led to a dramatic increase in inequality within and across countries. Preliminary evidence suggests that the recovery from the crisis will be as uneven as its initial economic impacts, with emerging economies and economically disadvantaged groups needing much more time to recover from pandemic-induced losses of income and livelihoods. Now there is a sense of introspection in people. India has emerged stronger.”
Your task is to write a program that analyzes and encrypts this text using the following rules.
Step 1: Character Encryption
Convert every character in the text into a numeric value based on the following mapping:
•	Lowercase letters:
a = 1, b = 2, c = 3, ... , z = 26
•	Uppercase letters:
A = 27, B = 28, C = 29, ...
•	Space = 0
•	Full stop (.) = 99
Example:
COVID crisis →
29 41 48 35 30 0 3 18 9 19 9 19
Level 1 – Basic Encryption
1.	Convert the entire text into encrypted digits using the rules above.
2.	Display the encrypted sequence.
3.	Calculate and display the sum of all encrypted digits.
*/