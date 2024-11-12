/*
Sort a k sorted doubly linked list
Given a doubly linked list, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. 
The distance can be assumed in either of the directions (left and right).
*/
#include<bits/stdc++.h>
using namespace std;

class DLLNode{
public:
	int data;
	DLLNode* next;
	DLLNode* prev;
	
	DLLNode(int _data){
		data = _data;
		next = nullptr;
		prev = nullptr;
	}
};

class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        DLLNode *res = new DLLNode(INT_MIN);
        DLLNode *temp = res; // Resultant variable
        DLLNode *curr = head; // Traversing through original DLL
        
        priority_queue<int , vector<int> , greater<int>>pq;
        int size = 1;
        pq.push(curr->data);
        curr = curr->next;
        while(not pq.empty()){
            if(curr != nullptr and size <= k){
                pq.push(curr->data);
                curr = curr->next;
                size++;
            }else{
                DLLNode *dummy = new DLLNode(pq.top());
                pq.pop();
                temp->next = dummy;
                dummy->prev = temp;
                temp = temp->next;
                size--;
                
                if(curr){
                    pq.push(curr->data);
                    curr = curr->next;
                    size++;
                }
            }
        }
        
        return res->next;
    }
};

int main(){
	
}
