#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data){
        val=data;
        right=nullptr;
        left=nullptr;
    }
};

void levelorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    vector<string> ans;
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();

        if(node==nullptr){
            ans.push_back("null");
        }
        else{
            ans.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        }
    }

    while(!ans.empty() && ans.back()=="null"){
        ans.pop_back();
    }

    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i+1<ans.size()){
            cout<<",";
        }
    }
    cout<<"]";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    stack<TreeNode*> st;
    int i=0;
    int n=s.size();
    
    while(i<n){
        int depth=0;
        while(i<n && s[i]=='-'){
            depth++;
            i++;
        }
        int val=0;
        while(i<n && isdigit(s[i])){
            val=val*10;
            val+=s[i]-'0';
            i++;
        }

        TreeNode* newnode=new TreeNode(val);
        while(st.size() > depth){
            st.pop();
        }
        if(!st.empty()){
            if(st.top()->left==nullptr){
                st.top()->left=newnode;
            }
            else{
                st.top()->right=newnode;
            }
        }
        st.push(newnode);
    }

    while(st.size()>1){
        st.pop();
    }

    TreeNode* newnode=st.top();
    levelorder(newnode);
    
    
    return 0;
}











/*We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

 

Example 1:


Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:


Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
Example 3:


Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]
 

Constraints:

The number of nodes in the original tree is in the range [1, 1000].
1 <= Node.val <= 109*/