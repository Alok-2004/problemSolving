/*
Find length of Loop
Given the head of a linked list, determine whether the list contains a loop. 
If a loop is present, return the number of nodes in the loop, otherwise return 0.
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node* next;
public:
    Node(int val) {
        data = val;
        next = nullptr;    
    }

    friend class Solution;
};

class Solution {
public:
    int countNodesinLoop(Node *head) {
        bool check = false;
        int res = 0;
        Node* slow = head;
        Node* fast = head;
        Node* temp = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow) {
                check = true;
                slow = head;
                temp = fast;
                break;
            }
        }
        
        if (check) {
            while (temp != slow) {
                temp = temp->next;
                slow = slow->next;
            }
            
            res = 1;
            temp = temp->next;
            while (temp != slow) {
                temp = temp->next;
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    
    int loopLength = sol.countNodesinLoop(head);
    cout << "Length of the loop: " << loopLength << endl;
    
    return 0;
}

