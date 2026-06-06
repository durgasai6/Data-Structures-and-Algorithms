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
        if(n==1){
            cout<<x<<endl;
            return 0;
        }

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
    if(head == nullptr || head->next == nullptr){
        cout<<"empty list"<<endl;
        return 0;
    }
    Node* first=head;   
    Node* second=first->next;
    int i=0;
    Node* prev=head;

    while(first!=nullptr && second!=nullptr){
        if(i==0){
            first->next=second->next;
            second->next=first;
            head=second;
            i++;
        }else{
            first->next=second->next;
            second->next=first;
            prev->next=second;
        }
        prev=first;
        if(first->next==nullptr){
            break;
        }
        first=first->next;
        second=second->next;
        if(second==nullptr){
            break;
        }
        else{
            second=second->next;
            if(second==nullptr){
                break;
            }
            else{
                second=second->next;
            }
        }
    }

    first=head;
    while(first!=nullptr){
        cout<<first->val<<" ";
        first=first->next;
    }

    
    return 0;
}

















/*Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100*/