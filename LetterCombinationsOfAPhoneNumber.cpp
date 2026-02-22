#include<bits/stdc++.h>
using namespace std;

vector<string> result;
string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void dfs(int index, string &input, string current){
    if(index==input.size()){
        result.push_back(current);
        return;
    }
    string letters=mp[input[index]-'0'];
    for(char ch: letters){
        dfs(index+1,input,current+ch);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin>>input;
    if(input.empty()){
        return 0;
    }
    dfs(0,input,"");
    for(string &s : result){
        cout<<s<<" ";
    }
    return 0;
}





/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].*/