#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

using namespace std; 

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle found
    }
};

int main() {
    // Creating a linked list with a cycle
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b; // Creating a cycle

    Solution solution;

    if (solution.hasCycle(a)) {
        cout << "Linked list has a cycle." << endl;
    } else {
        cout << "Linked list does not have a cycle." << endl;
    }

    // Clean up memory (delete the linked list)
    while (a != nullptr) {
        ListNode* temp = a;
        a = a->next;
        delete temp;
    }

    return 0;
}
