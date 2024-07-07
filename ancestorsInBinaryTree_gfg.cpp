#include<bits/stdc++.h>
using namespace std;

class Node{
  int data;
  Node* left;
  Node* right;
  public:
  	Node(int val){
  	  data = val;
	  this->left = nullptr;
	  this->right = nullptr;	
	}
};

class Solution {
  public:
    bool helper(Node *root, int t, vector<int>&res){
        if(root == nullptr ) return false;
        if(root->data == t) return true;
        if(helper(root->left, t, res) || helper(root->right, t, res)){
            res.push_back(root->data);
            return true;
        }
        return false;
    }
  
    vector<int> Ancestors(Node *root, int target) {
      vector<int>res;
      if(root == nullptr) helper(root, target, res);
      return res;
    }
};
