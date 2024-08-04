#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            size++;
            curr = curr->next;
        }

        ListNode* temp = head;
        for (int i = 1; i <= size / 2; i++) {
            temp = temp->next;
        }
        return temp;
    }
    
    /*
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast->next){
            return slow->next;
        }

        return slow;
    }
    */
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    cout << "Middle node value: " << middle->val << endl;

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

