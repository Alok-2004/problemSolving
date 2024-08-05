// Bottom view

/*
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	Node *left;
	Node *right;
	int data;
	
	Node(int data){
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};
// using level order traversal
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> res;
        queue< pair<int,Node*> >q; // flag , node
        map<int,int>m; //flag , node data
        
        q.push( {0 , root} );
        while(!q.empty()){
        	pair<int , Node*>p = q.front();
        	q.pop();
        	m[p.first] = p.second->data;
        	if(p.second->left) q.push({p.first-1 , p.second->left});
        	if(p.second->right) q.push({p.first+1 , p.second->right});       	
		}
		
		for( pair<int , int>x : m){
			res.push_back(x.second);
		}
		return res;
    }
};
