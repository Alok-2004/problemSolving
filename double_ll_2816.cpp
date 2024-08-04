#include <iostream>
#include <vector>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* doubleIt(ListNode* head) {
    std::vector<ListNode*> lt;
    ListNode* temp = head;
    while (temp) {
        lt.push_back(temp);
        temp = temp->next;
    }
    int carry = 0;
    for (int i = lt.size() - 1; i >= 0; i--) {
        int num = carry + 2 * (lt[i]->val);
        lt[i]->val = num % 10;
        carry = num / 10;
    }

    if (carry > 0) {
        ListNode* dummy = new ListNode(carry);
        dummy->next = head;
        head = dummy;
    }

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* newHead = doubleIt(head);

    ListNode* current = newHead;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}

