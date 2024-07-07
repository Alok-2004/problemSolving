#include<bits/stdc++.h>

using namespace std;

class ListNode{
	public:
		int val;
		ListNode* next;
		
		ListNode(int data){
			val = data;
			next = nullptr;
		}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* cur = dummy;
        head = head->next;
        int sum = 0;
        while (head != nullptr) {
            if (head->val == 0) {
                cur->next = new ListNode(sum);
                cur = cur->next;
                sum = 0;
            }
            sum += head->val;
            head = head->next;
        }
        return dummy->next;
    }
};
