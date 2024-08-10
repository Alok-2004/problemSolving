/*
Rotate a Linked List
Given the head of a singly linked list, the task is to rotate the linked list clockwise by k nodes, i.e., left-shift the linked list by k nodes, 
where k is a given positive integer smaller than or equal to length of the linked list.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node(int val){
		this->val = val;
		next = nullptr;
	}	
};

//Inefficient
/*
class Solution {
public:
    int sizeOfLinkedList(Node* head){
        Node* temp = head;
        int res = 0;
        while(temp){
            res++;
            temp = temp->next;
        }
        return res;
    }
    
    Node* rotate(Node* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        int rtt = k % sizeOfLinkedList(head);
        
        Node* last = head;
        while(last->next != nullptr){
            last = last->next;
        }
        
        Node* temp = head;
        while(rtt){
            last->next = temp;
            temp = temp->next;
            last = last->next;
            last->next = nullptr;
            rtt--;
        }
        
        return temp;
    }
};
*/

//Using circular LinkedList

class Solution {
  public:
    
    int sizeOfLinkedList(Node* head){
        Node* temp = head;
        int res = 0;
        while(temp){
            res++;
            temp = temp->next;
        }
        return res;
    }
    
    Node* rotate(Node* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        k = k % sizeOfLinkedList(head);
        
        if(k == 0) return head;
        Node* last = head;
        while(last->next != nullptr){
            last = last->next;
        }
        
        last->next = head;
        
        Node* temp = head;
        while(k > 1){
        	temp = temp->next;
        	k--;
		}
		
		Node* newLast = temp;
		temp = temp->next;
		newLast->next = nullptr;
        return temp;
    }
};
