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
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    if(k==n){
        head=head->next;
        Node* t=head;
        while(t){
            cout<<t->val<<" ";
            t=t->next;
        }
        return 0;
    }
    Node* prev=head;
    for(int i=0;i<n-k-1;i++){
        prev=prev->next;
    }
    Node* temp=prev->next;

    prev->next=temp->next;
    temp->next=nullptr;

    temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }



    return 0;
}









/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?*/