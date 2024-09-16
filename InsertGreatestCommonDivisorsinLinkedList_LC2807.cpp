/*
2807. Insert Greatest Common Divisors in Linked List
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the 
greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that 
evenly divides both numbers.
*/

#include<bits/stdc++.h>
using namespace std;

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int gcd(int a , int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        while(first and second){
            int temp = gcd(first->val , second->val);

            ListNode* curr = new ListNode(temp);

            first->next = curr;
            curr->next = second;

            second = second->next;
            first = curr->next;
        }

        return head;
    }
};

int main(){
	
}
