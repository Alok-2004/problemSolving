/*
Diameter of a Binary Tree
Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. 
This path may or may not pass through the root. Your task is to find the diameter of the tree.
*/

#include<bits/stdc++.h>
using namesapce std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
  public:
    int maxDiameter = 0;

    int dfs(Node* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        maxDiameter = max(maxDiameter, left + right);
        return 1 + max(left, right);
    }

    int diameter(Node* root) {
        dfs(root);
        return maxDiameter;
    }
};

int main(){
	
}
