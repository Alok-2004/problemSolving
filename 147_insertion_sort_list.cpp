
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* newHead = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* next = curr->next;

        if (newHead == nullptr || curr->val < newHead->val) {
            curr->next = newHead;
            newHead = curr;
        } else {
            ListNode* temp = newHead;
            while (temp->next != nullptr && temp->next->val < curr->val) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }

        curr = next;
    }

    return newHead;
}

};
