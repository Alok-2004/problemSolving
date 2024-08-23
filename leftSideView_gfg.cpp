/*
Left View of Binary Tree
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.
*/

#include<bits/stdc++.h>
using namespace std;
//PreOrder Traversal
/*
class Solution{
public:
	void preorder(Node* root , int level , vector<int>&res){
	    if(root == nullptr) return;
	    if(res.size() < level){
	        res.push_back(root->data);
	    }
	    preorder(root->left , level+1 , res);
	    preorder(root->right , level+1 , res);
	}
	
	vector<int> leftView(Node *root){
	    if(root == nullptr) return {};
	    vector<int>res;
	    preorder(root , 1 , res);
	    return res;
	}
};
*/

//Level Order Traversal
class Solution{
public:
	vector<int> leftView(Node* root) {
	    if (root == nullptr) return {};
	    queue<Node*> q;
	    q.push(root);
	    vector<int> res;
	    while (!q.empty()) {
	        int size = q.size();
	        res.push_back(q.front()->data);
	        while (size > 0) {
	            Node* temp = q.front();
	            q.pop();
	            if (temp->left) q.push(temp->left);
	            if (temp->right) q.push(temp->right);
	            size--;
	        }
	    }
	    return res;
	}
};
