#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=nullptr;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newnode=new Node(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    if(k==0){
        return 0;
    }
    vector<Node*> ans(k,nullptr);
    int idx=0;
    Node* temp=head;
    if(n<=k){
        while(temp!=nullptr){
            ans[idx]=temp;
            Node* nxt=temp->next;
            temp->next=nullptr;
            temp=nxt;
            idx++;
        }
    }else{
        idx=0;
        int sz=n/k;
        int extra=n%k;
        
        while(extra--){
            ans[idx]=temp;
            Node* prev=nullptr;
            for(int i=0;i<sz+1;i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=nullptr;
            idx++;
        }
        while(temp!=nullptr){
            ans[idx]=temp;
            Node* prev=nullptr;
            for(int i=0;i<sz;i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=nullptr;
            idx++;
        }
    }
    for(int i=0;i<k;i++){
        Node* curr=ans[i];
        while(curr!=nullptr){
            cout<<curr->val<<" ";
            curr=curr->next; 
        }
        cout<<endl;
    }






    return 0;
}