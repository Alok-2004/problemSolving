// Leetcode 237
/*
solution

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
*/
#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* deletenode(Node* head, int target) {
    if (head == nullptr) {
        return head; // Nothing to delete, return the head as it is.
    }

    if (head->val == target) {
        Node* temp = head;
        head = head->next;
        //delete temp;
        return head;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->val != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Node with value " << target << " not found." << endl;
        return head;
    } else if (temp->next->next == NULL) {
        temp->next = NULL;
        return head;
    } else {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        //delete toDelete;
        return head;
    }
}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    Node* head = a;

    display(head);

    int target;
    cout << "Enter the value of the node you want to delete: ";
    cin >> target;

    head = deletenode(head, target);
    display(head);

    return 0;
}
