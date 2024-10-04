/*
Deletion and Reverse in Circular Linked List
Given a Circular Linked List. The task is to delete the given node, key in the circular linked list, 
and reverse the circular linked list.

Note:
You don't have to print anything, just return the head of the modified list in each function.
Nodes may consist of Duplicate values.
The key may or may not be present.
*/
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nex = nullptr;
        
        while (curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        
        return prev;
    }

    Node* deleteNode(Node* head, int key) {
        Node* temp = head;
        
        while (temp->next != head) {
            temp = temp->next;
        }
        
        temp->next = nullptr;
        
        Node* dummy = new Node(-1);
        dummy->next = head;
        
        Node* prev = dummy;
        temp = head;
        
        while (temp) {
            if (temp->data != key) {
                prev->next = temp;
                prev = prev->next;
            }
            temp = temp->next;
        }
        
        head = dummy->next;
        delete dummy;

        Node* newHead = reverse(head);

        temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        
        temp->next = newHead;

        return newHead;
    }
};

void printList(Node* head) {
    if (!head) return;
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Helper function to create a circular linked list from an array
Node* createCircularLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    
    temp->next = head;  // Making the list circular
    return head;
}

int main() {
    int arr[] = {10, 7, 8, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8; 
    Node* head = createCircularLinkedList(arr, n);
    Solution sol;
    cout << "Original list: ";
    printList(head);
    head = sol.deleteNode(head, key);
    cout << "List after deleting " << key << " and reversing: ";
    printList(head);
    return 0;
}

