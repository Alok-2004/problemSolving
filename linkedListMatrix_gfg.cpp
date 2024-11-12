/*
Linked List Matrix
Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* right;
	Node* down;
	
	Node(int _data){
		data = _data;
		right = nullptr;
		down = nullptr;
	}
};

class Solution{
public:
	
	Node* constructLinkedMatrix( vector<vector<int>>& mat ){
		
		vector<Node*> heads(mat.size() , new Node(INT_MAX));
		
		for(int i = 0 ;i < mat.size(); i++){
			Node* temp = heads[i];
			for(int j = 0 ; j < mat[0].size() ; j++){
				temp->right = new Node(mat[i][j]);
				temp = temp->right;
			}
			heads[i] = heads[i]->right;	
		}
		
		for(int i = 0 ; i < heads.size()-1; i++){
			Node*  temp = heads[i];
			Node* prev = heads[i];
			
			temp->down = heads[i+1];
			temp = temp->right;
			
			while(temp){
				temp->down = prev->down->right;
				prev = temp;
				temp = temp->right;
			}
		}	
		return heads[0];
	}	
};

int main(){
	
}
