#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,del;
    cin>>n>>del;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newnode=new Node(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node* temp=head;
    while(temp->data!=del){
        temp=temp->next;
    }
    Node* after=temp->next;
    temp->data=after->data;
    temp->next=after->next;
    delete after;

    Node* t=head;
    while(t!=nullptr){
        cout<<t->data<<" ";
        t=t->next;
    }

    return 0;
}