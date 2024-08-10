#include<iostream>
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
// second approach go to nth node then change the pointer
        // find the length
        // find tail
        int n = 0;
        ListNode *temp = head;
        ListNode *tail = NULL;
        while(temp != NULL){
            if(temp -> next == NULL)  tail = temp;
            temp = temp->next;
            n++;
        }

        if( n == 1 || n == 0){
            return head;
        }

        k = k % n;

        if( k == 0)  return head;

        temp =  head;
        for(int i = 1; i<n - k; i++){
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

int main(){
	
}
