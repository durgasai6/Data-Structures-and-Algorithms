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

Node* reverselist(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    Node* head1=nullptr;
    Node* head2=nullptr;
    Node* tail1=nullptr;
    Node* tail2=nullptr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newnode=new Node(x);
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

    Node* temp1=head1;
    Node* temp2=head2;
    int sum=0,carry=0;

    Node* anshead=nullptr;
    Node* anstail=nullptr;
    int idx=0;

    for(int i=0;i<min(n,m);i++){
        sum=temp1->val + temp2->val + carry;
        if(sum>=10){
            Node* newnode=new Node(sum%10);
            carry=1;
            if(anshead==nullptr){
                anshead=newnode;
                anstail=newnode;
            }
            else{
                anstail->next=newnode;
                anstail=newnode;
            }
        }
        else{
            carry=0;
            Node* newnode=new Node(sum);
            if(anshead==nullptr){
                anshead=newnode;
                anstail=newnode;
            }
            else{
                anstail->next=newnode;
                anstail=newnode;
            }
        }
        temp1=temp1->next;
        temp2=temp2->next;
        idx++;
    }   
    if(n!=m){
        int tl=max(n,m);
        for(int i=idx;i<tl;i++){
            if(tl==n){
                Node* t=temp1;
                sum=t->val + carry;
                if(sum>=10){
                    carry=1;
                    Node* newnode=new Node(sum%10);
                    if(anshead==nullptr){
                        anshead=newnode;
                        anstail=newnode;
                    }
                    else{
                        anstail->next=newnode;
                        anstail=newnode;
                    }
                }
                else{
                    carry=0;
                    Node* newnode=new Node(sum);
                    if(anshead==nullptr){
                        anshead=newnode;
                        anstail=newnode;
                    }
                    else{
                        anstail->next=newnode;
                        anstail=newnode;
                    }
                }
                temp1=temp1->next;
            }
            else{
                Node* t=temp2;
                sum=t->val + carry;
                if(sum>=10){
                    carry=1;
                    Node* newnode=new Node(sum%10);
                    if(anshead==nullptr){
                        anshead=newnode;
                        anstail=newnode;
                    }
                    else{
                        anstail->next=newnode;
                        anstail=newnode;
                    }
                }
                else{
                    carry=0;
                    Node* newnode=new Node(sum);
                    if(anshead==nullptr){
                        anshead=newnode;
                        anstail=newnode;
                    }
                    else{
                        anstail->next=newnode;
                        anstail=newnode;
                    }
                }
                temp2=temp2->next;
            }
        }
    }
    if(carry!=0){
        Node* finalnode=new Node(carry);
        anstail->next=finalnode;
        anstail=finalnode;
    }


    Node* ans=anshead;
    while(ans!=nullptr){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}















/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/