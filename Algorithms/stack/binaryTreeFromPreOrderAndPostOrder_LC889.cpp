/*
889. Construct Binary Tree from Preorder and Postorder Traversal
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int _val){
		val = _val;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        stack<TreeNode*>st;
        TreeNode* root = new TreeNode(pre[0]);
        st.push(root);
        int preIdx = 1;
        int postIdx = 0;

        while(preIdx < pre.size()){
            auto temp = st.top();
            if(post[postIdx] == temp->val){
                st.pop();
                postIdx++;
            }
            else{
                TreeNode* curr = new TreeNode(pre[preIdx]);
                if(temp->left){
                    temp->right = curr;
                }else{
                    temp->left = curr;
                }
                st.push(curr);
                preIdx++;
            }
        }

        return root;   
    }
};

int main(){
	
}
