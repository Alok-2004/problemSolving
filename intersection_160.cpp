#include<iostream>
#include <cstdlib>
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

int siz(Node *head)
{
    int siz = 0;
    Node *curr = head;
    while(curr != NULL)
    {
        siz++;
        curr = curr->next;
    }
    return siz;
}

Node* intersection(Node *headA, Node *headB)
{
    int a = siz(headA);
    int b = siz(headB);
    int c = abs(a-b);
    Node* tempA = headA;
    Node* tempB = headB;

    if(a>b)
    {
        for(int i = 1; i<=c; i++)
        {
            tempA = tempA->next;
        }
        while(tempA->val != tempB->val)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
    else
    {
        for(int i = 1; i<=c; i++)
        {
            tempB = tempB->next;
        }
        while(tempA->val != tempB->val)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempB;
    }
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

    cout << "Original List 1: ";
    printList(a);

    Node *w = new Node(100);
    Node *s = new Node(10);
    Node *t = new Node(20);
    Node *u = new Node(30);
    Node *v = new Node(40);

    w->next = s;
    s->next = t;
    t->next = u;
    u->next = v;
    v->next = NULL;

    cout << "Original List 2: ";
    printList(w);

    Node* result = intersection(a, w);

    if (result != nullptr)
    {
        cout << "Intersection Point: " << result->val << endl;
        printList(result);
    }
    else
    {
        cout << "No intersection found." << endl;
    }

    // Clean up memory (delete the remaining nodes)
    while (a != nullptr)
    {
        Node *temp = a;
        a = a->next;
        delete temp;
    }

    while (w != nullptr)
    {
        Node *temp = w;
        w = w->next;
        delete temp;
    }

    return 0;
}


/*
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }

        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA; // This is the intersection node or nullptr if there's no intersection
    }

private:
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};

*/
