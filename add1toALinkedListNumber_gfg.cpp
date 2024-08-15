/*
Add 1 to a Linked List Number
You are given a linked list where each element in the list is a node and have an integer data. 
You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 
Note: The head represents the first element of the given array.
*/

//TC of O(n) and SC of O(n) due to recursive stack

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

/*
class Solution {
  public:
    int helper(Node* head){
        if(head->next == nullptr){
            int x = head->data;
            x = x+1;
            head->data = x%10;
            return x/10;
        }
        
        int x = head->data;
        x = x+helper(head->next);
        head->data = x%10;
        return x/10;
    }
  
    Node* addOne(Node* head) {
        int carry = helper(head);
        if(carry > 0){
            Node* res = new Node(carry);
            res->next = head;
            return res;
        }
        else{
            return head;
        }
    }
};
*/

//Space complexity of O(1)
class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* n = nullptr;
        
        while (curr != nullptr) {
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }

    Node* addOne(Node* head) {
        head = reverseList(head);
        Node* curr = head;
        int carry = 1;
        while (curr != nullptr) {
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            if (carry == 0) break;
            if (curr->next == nullptr && carry > 0) {
                curr->next = new Node(carry);
                carry = 0;
            }
            curr = curr->next;
        }
        head = reverseList(head);
        
        return head;
    }
};

int main(){
	
}
