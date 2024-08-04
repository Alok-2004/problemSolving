#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode *c = new ListNode(0); 
        ListNode *temp = c;

        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }

        if (a == NULL) {
            temp->next = b;
        } else {
            temp->next = a;
        }

        return c->next; 
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())  
            return NULL;
        
        while (lists.size() > 1) {
            ListNode* a = lists[0]; 
            lists.erase(lists.begin());
            ListNode* b = lists[0];
            lists.erase(lists.begin());
            ListNode* merged = merge(a, b);
            lists.push_back(merged);  
        }
        
        return lists[0];
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

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
    vector<ListNode*> lists;

    ListNode* list1 = nullptr;
    insert(&list1, 1);
    insert(&list1, 4);
    insert(&list1, 5);

    ListNode* list2 = nullptr;
    insert(&list2, 1);
    insert(&list2, 3);
    insert(&list2, 4);

    ListNode* list3 = nullptr;
    insert(&list3, 2);
    insert(&list3, 6);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    Solution solution;
    ListNode* mergedList = solution.mergeKLists(lists);

    std::cout << "Merged list:\n";
    printList(mergedList);

    return 0;
}

