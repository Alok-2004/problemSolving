/*
641. Design Circular Deque
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int>dq;
    int head;
    int tail;
    int k , size;

    MyCircularDeque(int k) {
        this->k = k;
        dq = vector<int>(k, -1);
        head = 0;
        tail = 0;
        size = 0;
    }
    
    bool insertFront(int value) {
        if( isFull() ) return false;

        head = (head - 1 + k) % k;
        dq[head] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if( isFull() ) return false;
        dq[tail] = value;
        tail = (tail + 1) % k;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty() ) return false;
        size--;
        head = (head + 1) % k;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty() ) return false;
        size--;
        tail = (tail - 1 + k) % k;
        return true;
    }
    
    int getFront() {
        if( !isEmpty() ) return dq[head];
        else return -1;
    }
    
    int getRear() {
        if( !isEmpty() ) return dq[(tail-1+k) % k];
        else return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

int main(){
}
