/*
Root to leaf paths sum
Given a binary tree, where every node value is a number. 
Find the sum of all the numbers that are formed from root to leaf paths. 
The formation of the numbers would be like 10*parent + current 
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int _data){
		data = _data;
		left = right = nullptr;
	}
};

class Solution {
public:  
    void solve(Node* root , int local , int &res){
        local = local*10 + root->data;
        if(!root->left and !root->right){
            res += local;
            return;
        }
        if(root->left) solve(root->left , local , res);
        if(root->right) solve(root->right , local , res);
    }
    
    int treePathsSum(Node *root) {
        int res = 0;
        solve(root , 0 , res);
        
        return res;
    }
};

int main(){
	
}
