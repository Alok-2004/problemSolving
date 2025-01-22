/*
Add Number Linked Lists
Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:

    Node *reverse(Node *head) {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node *addListRec(Node *num1, Node *num2, int &carry) {

        if (num1 == nullptr && num2 == nullptr && carry == 0) {
            return nullptr;
        }

        int sum = carry;

        if (num1 != nullptr) {
            sum += num1->data;
            num1 = num1->next;
        }

        // Add the value from the second list if it exists
        if (num2 != nullptr) {
            sum += num2->data;
            num2 = num2->next;
        }
    
        carry = sum / 10;
        Node *result = new Node(sum % 10);
    
        result->next = addListRec(num1, num2, carry);
    
        return result;
    }

    Node* trimLeadingZeros(Node* head) {
        while (head != nullptr && head->data == 0) {
            head = head->next;
        }
        return head;
    }

    Node *addTwoLists(Node *num1, Node *num2) {
        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);
    
        num1 = reverse(num1);
        num2 = reverse(num2);
    
        int carry = 0;
        Node *result = addListRec(num1, num2, carry);
    
        if (carry != 0) {
            Node *newNode = new Node(carry);
            newNode->next = result;
            result = newNode;
        }
    
        return reverse(result);
    }

};

int main(){
	
}
