/*
Multiply two linked lists
Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

Note: The output could be large take modulo 109+7.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int _data){
		data = _data;
		next = nullptr;
	}
};

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long curr = 0;
        long long mod = 1000000007;
        Node* temp = first;
        
        while(temp){
            curr = curr*10 + temp->data;
            temp = temp->next;
        }
        long long res = 0;
        temp = second;
        
        while(temp){
            res = res*10 + curr*temp->data;
            res = res % mod;
            temp = temp->next;
        }
        
        return res;
        
    }
};

int main(){
	
}
