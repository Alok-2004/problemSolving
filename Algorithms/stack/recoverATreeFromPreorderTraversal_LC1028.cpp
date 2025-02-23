/*
1028. Recover a Tree From Preorder Traversal	
We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* recoverFromPreorder(string trav) {
        int n = trav.size();
        
        stack< pair<int ,TreeNode*> >st;
 
        string num = "";
        int i = 0;
        while(i < n and trav[i] != '-'){
            num += trav[i];
            i++;
        }
        
        
        TreeNode* root = new TreeNode(stoi(num));
        st.push({0 , root});

        int count = 0;
        while(i < n){
            while( i < n and trav[i] == '-'){ 
                i++;
                count++;
            }

            string temp = "";
            while(i < n and trav[i] != '-'){
                temp += trav[i];
                i++;
            }

            while(!st.empty() and st.top().first >= count){
                st.pop();
            }
                
            TreeNode* curr = new TreeNode(stoi(temp));
            if (!st.empty()) {
                if(st.top().second->left) st.top().second->right = curr;
                else st.top().second->left = curr;
            }
            st.push({count , curr});
            count = 0;
        }

        return root;
    }
};

int main(){
	
}
