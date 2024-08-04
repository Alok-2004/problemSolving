#include<iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void remove(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        // Invalid index or empty list, nothing to remove.
        return;
    }

    if (n == 1)
    {
        // Special case: Remove the first node.
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    int len = 1;
    Node *curr = head;

    while (len < n - 1 && curr->next != NULL)
    {
        len++;
        curr = curr->next;
    }

    if (len < n - 1 || curr->next == NULL)
    {
        // Index out of range, do nothing.
        return;
    }

    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    cout << "Original List: ";
    printList(a);

    cout << "Enter the index to remove (1-based indexing): ";
    int idx;
    cin >> idx;

    remove(a, idx);

    cout << "Updated List: ";
    printList(a);

    // Clean up memory (delete the remaining nodes)
    while (a != nullptr)
    {
        Node *temp = a;
        a = a->next;
        delete temp;
    }

    return 0;
}
/*
ListNode* removeNthFromEnd(ListNode *head, int n)
{
    ListNode* slow = Head;
    ListNode* fast = Head;

    for(int i = 1; i<n+1; i++)
    {
        if(fast == NULL) return head->next;
        fast = fast->next;
    }

    // move slow and fast at same pace
    while(fast!=NULL)
    {
        slow = slow->next;
        fats = fast->next;
    }

    // now the slow is exactly at the left of the target element
    ListNode* toRemove = slow->next;
    slow->next = slow->next->next;
    delete toRemove;
    return head;
}
