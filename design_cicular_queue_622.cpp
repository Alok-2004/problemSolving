#include<iostream>
#include<vector>

using namespace std;

class MyCircularQueue {
public:
    int f, b, s, c; // front back, size, count
    vector<int> arr;

    MyCircularQueue(int k) {
        f = 0; 
        b = 0; 
        s = 0; 
        c = k;
        arr.resize(k);     
    }
    
    bool enQueue(int value) {
        if(s == c)  return false;
        arr[b] = value;
        b++;
        if(b == c)  b = 0;
        s++;
        return true;
    }
    
    bool deQueue() {
        if(s == 0) return false;
        f++;
        if(f == c) f = 0;
        s--;
        return true;
    }
    
    int Front() {
        if(s == 0) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(s == 0) return -1;
        if(b == 0) return arr[c - 1];
        return arr[b - 1];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        return s == c;
    }
};
