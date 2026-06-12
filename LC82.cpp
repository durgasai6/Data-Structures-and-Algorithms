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
    Node* temp=head;
    unordered_map<int,int> mp;
    while(temp){
        mp[temp->val]++;
        temp=temp->next;
    }

    temp=head;
    Node* newhead=nullptr;
    Node* newtail=nullptr;
    while(temp){
        if(mp[temp->val]==1){
            Node* newnode= new Node(temp->val);
            if(newhead==nullptr){
                newhead=newnode;
                newtail=newnode;
            }
            else{
                newtail->next=newnode;
                newtail=newnode;
            }
        }
        temp=temp->next;
    }
    temp=newhead;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    return 0;
}

















/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.*/