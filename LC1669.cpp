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
    int n,m;
    cin>>n>>m;
    Node* head1=nullptr;
    Node*tail1=nullptr;
    Node* head2=nullptr;
    Node* tail2=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newnode= new Node(x);
        if(head1==nullptr){
            head1=newnode;
            tail1=newnode;
        }
        else{
            tail1->next=newnode;
            tail1=newnode;
        }
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        Node* newnode=new Node(x);
        if(head2==nullptr){
            head2=newnode;
            tail2=newnode;
        }
        else{
            tail2->next=newnode;
            tail2=newnode;
        }
    }
    int a,b;
    cin>>a>>b;
    Node* t2=head1;
    for(int i=0;i<b;i++){
        t2=t2->next;
    }
    t2->next=nullptr;

    Node* t1=head1;
    for(int i=0;i<a-1;i++){
        t1=t1->next;
    }
    t1->next=head2;
    tail2->next=tail1;

    t1=head1;
    while(t1!=nullptr){
        cout<<t1->val<<" ";
        t1=t1->next;
    }

    return 0;
}














/*You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
 

Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104*/