#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,maxWidth;
    cin>>n>>maxWidth;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    string ans="";
    for(int i=0;i<n;i++){
        ans+=words[i];
        if(i!=n-1){
            ans+=" ";
        }
    }
    int sz=0;
    int index=0;
    vector<int> idx;
    idx.push_back(0);
    int i=0;
    while(i<ans.size()){
        if(ans[i]==' '){
            index=i+1;
        }
        if(sz>=maxWidth){
            idx.push_back(index-1);

            i=index;
            sz=0;
        }
        i++;
        sz++;
    }
    idx.push_back(ans.size()-1);
    for(int i=0;i<idx.size()-1;i++){
        int left= (i==0 ? idx[i] : idx[i]+1);
        int right=idx[i+1];
        string part=ans.substr(left,right-left+1);
        vector<string> temp;
        stringstream ss(part);
        string word;
        while(ss>>word){
            temp.push_back(word);
        }
        int chars=0;
        for(auto &w:temp){
            chars+=w.size();
        }
        int gaps=temp.size()-1;
        if(temp.empty()){
            continue;
        }
        if(gaps==0){
            
            string line=temp[0];
            line.append(maxWidth-line.size(),' ');
            cout<<line<<endl;
            continue;
        }
        int totalspaces=maxWidth-chars;
        int each=totalspaces/gaps;
        int extra=totalspaces%gaps;
        string line="";
        for(int j=0;j<temp.size();j++){
            line+=temp[j];
            if(j<gaps){
                line.append(each,' ');
                if(extra){
                    line+=" ";
                    extra--;
                }
            }
        }
        cout<<line<<endl;
    }

    return 0;
}