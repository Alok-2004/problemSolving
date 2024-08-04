#include<iostream>
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *curr = head;

        ListNode *dummy = new ListNode(10);
        dummy->next = head;
        ListNode *prev = dummy;
        while(curr){
            if(curr->val == val){
                curr = curr->next;
                prev->next = curr;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
