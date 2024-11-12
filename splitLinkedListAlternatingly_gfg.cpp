/*
Split Linked List Alternatingly
Given a singly linked list's head. 
Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
Note: 

The sublist should be in the order with respect to the original list.
Your have to return an array containing the both sub-linked lists.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int _data){
		data = _data;
		next = nullptr;
	}
};

class Solution {
  public:
    vector<Node*> alternatingSplitList( Node* head) {
        Node* firstList = nullptr;
        Node* secondList = nullptr;
        Node* firstTail = nullptr;
        Node* secondTail = nullptr;

        Node* current = head;
        bool flag = true;

        while (current != nullptr) {
            if (flag) {
                if (firstList == nullptr) {
                    firstList = current;
                    firstTail = firstList;
                } else {
                    firstTail->next = current;
                    firstTail = firstTail->next;
                }
            } else {
                if (secondList == nullptr) {
                    secondList = current;
                    secondTail = secondList;
                } else {
                    secondTail->next = current;
                    secondTail = secondTail->next;
                }
            }
            current = current->next;
            flag = !flag;
        }

        if (firstTail != nullptr) firstTail->next = nullptr;
        if (secondTail != nullptr) secondTail->next = nullptr;

        return {firstList, secondList};
    }
};


int main(){
	
}
