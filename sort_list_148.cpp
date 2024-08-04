#include <iostream>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// will using the concept of merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Helper function to insert a new node in the linked list
void insert(ListNode** head, int value) {
    ListNode* newNode = new ListNode(value);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        ListNode* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    ListNode* head = nullptr;

    // Insert elements into the list
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 3);

    std::cout << "Original list:\n";
    printList(head);

    // Sort the list
    Solution solution;
    ListNode* sortedHead = solution.sortList(head);

    std::cout << "Sorted list:\n";
    printList(sortedHead);

    return 0;
}

