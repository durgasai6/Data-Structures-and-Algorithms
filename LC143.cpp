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

Node* reverselist(Node* head){
    Node* newhead=nullptr;

    while(head){
        Node* temp=new Node(head->val);
        temp->next=newhead;
        newhead=temp;

        head=head->next;
    }
    return newhead;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

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

    Node* rev=reverselist(head);
    Node* newhead=nullptr;
    Node* newtail=nullptr;
    int i=0;
    while(n--){
        Node* temp=nullptr;
        if(i%2==0){
            temp=new Node(head->val);
            head=head->next;
        }
        else{
            temp=new Node(rev->val);
            rev=rev->next;
        }

        if(newhead==nullptr){
            newhead=temp;
            newtail=temp;
        }
        else{
            newtail->next=temp;
            newtail=temp;
        }
        i++;
    }

    Node* temp=newhead;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}
























/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000*/