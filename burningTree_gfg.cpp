//Burning Tree

/*
Burning Tree
Given a binary tree and a node data called target. 
Find the minimum time required to burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. 
That is its left child, right child, and parent.
Note: The tree contains unique values.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
//Steps
//1. Create nodeToParent mapping
//2. Find Target Node
//3. Burn the tree in min time

class Solution {
public:
    Node* mapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* res = nullptr;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = nullptr;
        
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            if (front->data == target) {
                res = front;    
            }
            
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int burnTree(Node* targetNode, map<Node*, Node*>& nodeToParent) {
        map<Node*, bool> mp;
        queue<Node*> q;
        
        mp[targetNode] = true;
        q.push(targetNode);
        
        int ans = 0;
        
        while (!q.empty()) {
            int size = q.size();
            int flag = 0;
            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();
                if (front->left && !mp[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    mp[front->left] = true;    
                }
                
                if (front->right && !mp[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    mp[front->right] = true;    
                }
                
                if (nodeToParent[front] && !mp[nodeToParent[front]]) {
                    q.push(nodeToParent[front]);
                    mp[nodeToParent[front]] = true;
                    flag = 1;
                }
            }
            if (flag == 1) ans++;
        }
        return ans;
    }

    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = mapping(root, target, nodeToParent);
        return burnTree(targetNode, nodeToParent);
    }
};


int main(){
	
}
