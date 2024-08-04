#include<iostream>
using namespace std;

// M - 1
/*
Bad [t.c = O(n^2)] -> getNodeAtidx
*/

//M - 2
/*
make new linked list of which is reverse of original linked list
TC and SC is of O(n)

class Solution{
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

		bool isPalindrome(ListNode *head){
			ListNode *c = new ListNode(10);// farzi node
			// deep copy of head;
			ListNode *temp = head;
			ListNode *tempC = c;
			while(temp){
				ListNode *node = new ListNode(temp->val);
				tempC ->next = node;
				tempC = tempC->next;
                temp = temp->next;
			}
			c = c->next;
			c = reverseList(c);
			ListNode *a = head;
			ListNode *b = c;
			while(a){
				if(a->val != b->val)  return false;
				a = a->next;
				b = b->next;
			}
			return true;
			
		}
};
*/
// M - 2 break the linkedlist in half and the revesere the second half and compare
class Solution{
	public:



int main(){
	
}
