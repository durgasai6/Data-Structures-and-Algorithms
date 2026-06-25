#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }
};

Node* build(){
    int x;
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    Node* root=new Node(x);
    root->left=build();
    root->right=build();

    return root;
}

void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root=build();
    cout<<"inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"preorder: ";
    preorder(root);

    return 0;
}