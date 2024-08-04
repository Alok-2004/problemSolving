#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* slow = dummy;
    ListNode* fast = head;

    while (fast) {
        int sum = 0;
        sum += fast->val;

        while (sum != 0 && fast->next) {
            fast = fast->next;
            sum += fast->val;
        }

        if (sum == 0) {
            slow->next = fast->next;
            fast = slow->next;
        } else {
            slow = slow->next;
            fast = slow->next;
        }
    }

    return dummy->next;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    std::cout << "Original Linked List: ";
    printList(head);

    ListNode* newHead = removeZeroSumSublists(head);

    cout << "Modified Linked List: ";
    printList(newHead);

    return 0;
}
