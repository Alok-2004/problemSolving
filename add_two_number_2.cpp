#include<iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution {
public:

    ListNode* numberToList(long long number) {
        if (number == 0) return new ListNode(0); // Edge case for number = 0

        ListNode* head = nullptr;
        ListNode** node = &head;
        while (number > 0) {
            *node = new ListNode(number % 10);
            number /= 10;
            node = &((*node)->next);
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long sum_l1 = 0;
        long long sum_l2 = 0;
        long long numOfZeroes = 1;
        while( l1 && l2){
            sum_l1 += l1->val * numOfZeroes;
            sum_l2 += l2->val * numOfZeroes;
            numOfZeroes *= 10;

            l1 = l1->next;
            l2 = l2->next;
             
        }

        // l1's length is more than l2
        while(l1){
            sum_l1 += l1->val * numOfZeroes;
            numOfZeroes *= 10;
            l1 = l1->next;
        }

        // l1's length is more than l2
        while(l2){
            sum_l2 += l2->val * numOfZeroes;
            numOfZeroes *= 10;
            l2 = l2->next;
        }

        return numberToList(sum_l1 + sum_l2);
    }
};
*/

class Solution{
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while(l1 && l2){
            int x = l1->val + l2->val + carry;
            curr->next = new ListNode(x%10);
            curr = curr->next;
            carry = x / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        // l1's length is more than l2
        while(l1){
            int x = l1->val + carry;
            curr->next = new ListNode(x%10);
            curr = curr->next;
            carry = x / 10;
            l1 = l1->next;
        }

        while(l2){
            int x = l2->val + carry;
            curr->next = new ListNode(x%10);
            curr = curr->next;
            carry = x / 10;
            l2 = l2->next;
        }

        if( carry > 0) {
            curr->next = new ListNode(carry);
        }

        return dummy->next;
    }
};

void printList(ListNode *node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int size) {
    ListNode *head = NULL, *temp = NULL, *p = NULL;
    for(int i = 0; i < size; i++) {
        temp = new ListNode(arr[i]);
        if (head == NULL) {
            head = temp;
        } else {
            p->next = temp;
        }
        p = temp;
    }
    return head;
}

int main() {
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode *l1 = createList(arr1, sizeof(arr1)/sizeof(arr1[0]));
    ListNode *l2 = createList(arr2, sizeof(arr2)/sizeof(arr2[0]));

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);
    while (l1 != NULL) {
        ListNode *temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != NULL) {
        ListNode *temp = l2;
        l2 = l2->next;
        delete temp;
    }

    while (result != NULL) {
        ListNode *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
