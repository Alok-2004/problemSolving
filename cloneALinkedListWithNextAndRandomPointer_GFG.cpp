/*
Clone a linked list with next and random pointer
You are given a special linked list where each node has a next pointer pointing to its next node. 
You are also given some random pointers, where you will be given some pairs denoting two nodes a and b i.e. a->random = b (random is a pointer to a random node).

Construct a copy of the given list. The copy should consist of the same number of new nodes, 
where each new node has its value set to the value of its corresponding original node. 
Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the original 
and copied list pointers represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes x and y in the original list, where x->random = y, 
then for the corresponding two nodes xnew and ynew in the copied list, xnew->random = ynew.

Return the head of the copied linked list.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* random;
	
	Node(int val){
		data = val;
		next = nullptr;
		random = nullptr;
	}
};


//Without Extra space
class Solution {
public:
    Node* copyList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;
	
	    while (temp != nullptr) {
            Node* newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        Node* dummy = new Node(INT_MIN);
        Node* curr = dummy;
        temp = head;
        while (temp != nullptr) {
            curr->next = temp->next;
            curr = curr->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};

//Using Extra space
/*
class Solution {
  public:
    Node *copyList(Node *head) {
        
        // Making the normal linked list
        Node* dummy = new Node(INT_MIN);
        Node* curr = dummy;
        Node* temp = head;
        
        unordered_map<Node* , Node*>orToNew;
        unordered_map<Node* , Node*>ran;
        while(temp != nullptr){
            Node* list = new Node(temp->data);
            
            curr->next = list;
            
            orToNew[temp] = list;
            ran[temp] = temp->random;
            
            curr = curr->next;
            temp = temp->next;
        }
        
        for( pair<Node* , Node*> ele : ran){
            
            Node* x = orToNew[ele.first];
            
            Node* y = orToNew[ele.second];
            
            x->random = y;
            
        }
        
        Node* rem = dummy;
        dummy = dummy->next;
        delete rem;
        return dummy;
    }
};
*/
