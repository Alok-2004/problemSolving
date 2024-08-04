#include<iostream>
using namespace std;
// Recursive method
class Solution {
	public:
	    ListNode* reverseList(ListNode* head){
		    if(head && head->next)   return head;
		    ListNode *newhead = reverseList(head->next);
		    head->next->next = head;
		    head->next = NULL;
		    return newhead;
		}
};

// Iterative method
class Solution {
	public:
	    ListNode* reverseList(ListNode* head){
		    ListNode* prev = NULL;
			ListNode* curr = head;
			ListNode* nex = head;
			while(curr){
				nex = curr->next;
				curr->next = prev;
				prev = curr;
				curr = nex;
			}
			return prev;
		}
};


