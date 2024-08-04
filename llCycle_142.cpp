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
    ListNode* detectCycle(ListNode* head) {
        bool flag = false;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                flag = true; // Cycle detected
                break;
            }
        }

        if (!flag)
            return nullptr; // No cycle found

        // Reset one pointer to the head and move both at the same pace
        ListNode* temp = head;
        while (temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }

        return slow; // Node where the cycle starts
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

    ListNode* cycleStart = solution.detectCycle(a);

    if (cycleStart != nullptr) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle found." << endl;
    }

    // Clean up memory (delete the linked list)
    while (a != nullptr) {
        ListNode* temp = a;
        a = a->next;
        delete temp;
    }

    return 0;
}
