/*
Get Min from Stack
Given q queries, You task is to implement the following four functions for a stack:

push(x) – Insert an integer x onto the stack.
pop() – Remove the top element from the stack.
peek() - Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
Each query can be one of the following:

1 x : Push x onto the stack.
2 : Pop the top element from the stack.
3: Return the top element from the stack. If the stack is empty, return -1.
4: Return the minimum element from the stack.
*/

#include<bits/stdc++.h>
using namespace std;

/*
Other methods
1. USe two another stack two store the min element
2. USe pair in stack i.e the number and min number
*/

// Only works when the range of x is between 1 to 100 
// Otherwise it may fail;
/*
class Solution {
  public:
    stack<int>st;
    Solution() {
    }

    void push(int x) {
        if(st.empty()){
            st.push(x*101 + x);
        }else{
            st.push(x * 101 + min(st.top() % 101, x));    
        }
        return;
    }

    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }

    int peek() {
        if(!st.empty()){
            return st.top() / 101;
        }else return -1;
    }

    int getMin() {
        if(!st.empty()){
            return st.top() % 101;
        }else return -1;
    }
};
*/

// Method to include larger range
class Solution {
  public:
    stack<int>st;
    int minEle;
    Solution() {
        minEle = -1;
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(st.empty()){
            st.push(x);
            minEle = x;
            return;
        }
        
        if(minEle > x){
            st.push(2*x - minEle);
            minEle = x;
        }else{
            st.push(x);
        }
        
        return;
        
    }

    // Remove the top element from the Stack
    void pop() {
        if(st.empty()){
            return;
        }
        
        int x = st.top();
        
        if(x < minEle){
            minEle = minEle * 2 - x;
        }
        
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        if(st.empty()){
            return -1;
        }
        
        int x = st.top();
        
        if(x < minEle){
            x = minEle;
        }
        
        return x;
    }

    // Finds minimum element of Stack
    int getMin() {
        if(!st.empty()){
            return minEle;
        }else return -1;
    }
};

int main(){
	
}
