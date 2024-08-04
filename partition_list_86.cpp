#include<iostream>
using namespace std;
class Solution {
	public:
		ListNode* partition(ListNode* head, int x){
		ListNode *low = new ListNode(-1);	
		ListNode *high = new ListNode(-1);
		
		ListNode *templo = low;
		ListNode *temphi = high;
		ListNode *temp = head;
		
		while(temp){
			if(temp->val < x){
				templo->next = temp;
				temp = temp->next;
				templo = templo->next;
			}else{
				temphi->next = temp;
				temp = temp->next;
				temphi = temphi->next;	
			}
		}
		templo->next = high->next;
		temphi->next = NULL;
		return low->next;
		}
};
int main(){
	return 0;
}
