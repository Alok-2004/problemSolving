/*
1381. Design a Stack With Increment Operation
Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. 
If there are less than k elements in the stack, increment all the elements in the stack.
*/
#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int>stack;
    int i;
    CustomStack(int maxSize) {
        stack.resize(maxSize , -1);
        i = 0;
    }
    
    void push(int x) {
        if(x > stack.size() - 1) return;
        stack[i] = x;
        i++;
    }
    
    int pop() {
        if(i == 0) return -1;
        int res = stack[i-1];
        i--;
        return res;
        
    }
    
    void increment(int k, int val) {
        for(int j = 0 ; j < min(i , k) ; j++){
            stack[j] += val;
        }
        return;
    }
};

int main(){
}
