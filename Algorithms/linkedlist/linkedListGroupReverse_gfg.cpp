/*
Linked List Group Reverse
Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int sz(Node* head){
        Node* temp = head;
        int s = 0;
        while(temp){
            s++;
            temp = temp->next;
        }
        
        return s;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nt = NULL;
        Node* end = head;
        while(curr){
            nt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nt;
        }
        
        return prev;
    }
    
    
    Node *reverseKGroup(Node *head, int k) {
        if (k == 1 || !head || !head->next) return head;
        
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prevGroupEnd = dummy;

        while (true) {
            Node* groupStart = prevGroupEnd->next;
            Node* groupEnd = prevGroupEnd;

            for (int i = 0; groupEnd->next && i < k; i++) {
                groupEnd = groupEnd->next;
            }
            
            Node* nextGroupStart = groupEnd->next;
            
            groupEnd->next = NULL;
            
            Node* reversedHead = reverse(groupStart);
            
            prevGroupEnd->next = reversedHead;
            
            if(!nextGroupStart) break;
            
            groupStart->next = nextGroupStart; 
            
            prevGroupEnd = groupStart;
            
        }

        return dummy->next;
    }
        
};

int main(){
	
}
