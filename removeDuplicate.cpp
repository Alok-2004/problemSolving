#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create a sorted linked list with duplicates
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(result);

    // Clean up memory (delete the linked list)
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}


/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
      ListNode*curr = head;
      while(curr != NULL && curr->next != NULL)
      {
        if(curr->val == curr->next->val)
        {
           curr->next = curr->next->next; 
        }
        else   curr = curr->next;
      }
      return head;
    }
};
*/
