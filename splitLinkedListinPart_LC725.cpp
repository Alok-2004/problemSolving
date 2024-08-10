/*
725. Split Linked List in Parts
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. 
This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size 
greater than or equal to parts occurring later.

Return an array of the k parts.
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* cur = head;
        while(cur != NULL){
            ++len;
            cur = cur->next;
        }

        vector<ListNode*> res(k,NULL);
        int sz = len/k;
        int rem = len%k;

        ListNode* curr = head;
        ListNode* prev = NULL;
        
        for(int i=0;i<k;i++){
            res[i] = curr;
            for(int j = 0;j < sz; j++){
                prev = curr;
                curr = curr->next;
            }
            if(rem > 0){
                if(curr != NULL){
                    prev = curr;
                    curr = curr->next;
                    --rem;
                }
            }
            if(prev != NULL){
                head = curr;
                prev->next = NULL;
            }
        }
        return res;
    }
};
