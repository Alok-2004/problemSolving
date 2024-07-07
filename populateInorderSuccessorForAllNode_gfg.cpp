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
    Node* previous = NULL;
    void populateNext(Node* root) {
        if (root == NULL)   return;
        populateNext(root->right);
        root->next = previous;
        previous = root;
        populateNext(root->left);
    }
};

int main(){
	
}
