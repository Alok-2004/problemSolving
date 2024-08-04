#include<iostream>

// Break the list in to equal halves uptill left middle 
// Reverse the second linklist
// make a dummy node
// and start joining the alternates 

class Solution {
public:
	
	ListNode *reverse(ListNode *head){
		ListNode *prev = NULL;
		ListNode *curr = head;
		ListNode *nex = head;
		while(curr){
			nex = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nex;
		}
		
		return prev;	
	}
	
    void reorderList(ListNode* head) {
    	
    	ListNode *fast = head;
    	ListNode *slow = head;
    	while(fast->next && fast->next->next){
    		slow = slow->next;
    		fast = fast->next->next;
		}
    	
    	ListNode *a = slow->next;
    	slow->next = NULL;
    	
    	ListNode *b = reverse(a);
    	
    	ListNode *dummyNode = new ListNode(-1);
    	ListNode *temp = dummyNode;

		ListNode *x = head;
		ListNode *xnext = head;
		ListNode *y = b;
		ListNode *ynext = b;
	
		while(x && y){
			xnext = x->next;
			x->next = NULL;
			temp->next = x;
			temp = temp->next;
			x = xnext;
			
			ynext = y->next;
			y->next = NULL;
			temp->next = y;
			temp = temp->next;
			y = ynext;
		}
		if(y){
			temp->next = y;
		}
        if(x){
			temp->next = x;
		}
    }
};
