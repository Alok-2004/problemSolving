#inlcude<iostream>

using namespace std;

// basically two aproach 1. Create 1 linkdlist and then work/farzi node
        // 2. merge in existing list/

        // Aproach 1
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempA = list1;
			ListNode* tempB = list2;
			ListNode* c = new ListNode(100);
			ListNode* tempC = c;
			while(tempA!=NULL && tempB!=NULL)
			{
				if(tempA->val <= tempB->val )
				{
					ListNode *t = new ListNode(tempA->val);
					
					tempC->next = t;
					tempC = t;
					tempA = tempA->next; 
				}
				else
				{
					ListNode *t = new ListNode(tempB->val);
					tempC->next = t;
					tempC = t;
					tempB = tempB->next;
				}
			}
			if(tempA==NULL)
			{
				tempC->next = tempB;
			}
			else{
				tempC->next = tempA;
			}
			return c->next;
    }
};
*/

// Aproach 2
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* c = new ListNode(100);
        ListNode* temp = c;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        temp->next = (list1 != NULL) ? list1 : list2;

        return c->next;
    }
};


int main{
	
}
