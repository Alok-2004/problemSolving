#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
  	int val;
  	Node* left;
  	Node* right;
  	
  	Node(int val){
  	  this->val = val;
	  this->left = nullptr;
	  this->right = nullptr;	
	}
};

class Solution {
  public:
  	
  	string serialized(Node* root, unordered_map<string, int> &m, vector<Node*> &res){
  	  if(root == nullptr) return "#";
  	  string temp = to_string(root->val) + " , " + serialized(root->left, m, res) + " , " + serialized(root->right, m, res);
  	  if (m.find(temp) != m.end()){
        if(m[temp] == 1)  res.push_back(root);
        m[temp]++;
      }
	  else  m[temp] = 1;
	  return temp;
	}
  	
    vector<Node*> printAllDups(Node* root) {
      vector<Node*>res;
	  if(root == nullptr) return res;
  	  unordered_map<string, int>m;
	  serialized(root, m, res);
	  return res;	 
    }
};

