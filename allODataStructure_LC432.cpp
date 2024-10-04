/*
432. All O`one Data Structure
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. 
It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.
*/

#include<bits/stdc++.h>
using namespace std;

// Brute force
/*
class AllOne {
public:
    unordered_map<string, int> freq;
    AllOne() {
       // nothing to do here
    }
    
    void inc(string key) {
        freq[key]++;
    }
    
    void dec(string key) {
        freq[key]--;
    }
    
    string getMaxKey() {
        int mx = 0;
        string ans = "";
        for(auto& val:freq){
            if(val.second > mx){
                mx = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
    
    string getMinKey() {
        int mini = INT_MAX;
        string ans = "";
        for(auto& val:freq){
            if(val.second!=0 and val.second < mini){
                mini = val.second;
                ans = val.first;
            }
        }
        return ans;
    }
};
*/

//Optimized
/*

class AllOne {
public:
    unordered_map<string, int> freq;
    set<pair<int,string>> st;
    AllOne() {
        // nothing to do here
    }
    
    void inc(string key) {
        st.erase({freq[key],key});
        freq[key]++;

        st.insert({freq[key], key});
    }
    
    void dec(string key) {
        st.erase({freq[key],key});
        freq[key]--;

        if(freq[key] > 0){
            st.insert({freq[key], key});
        }
    }
    
    string getMaxKey() {
        if(st.size()==0){return "";}
        string ans = prev(st.end())->second;
        return ans;
    }
    
    string getMinKey() {
        if(st.size()==0){return "";}
        string ans = st.begin()->second;
        return ans;
    }
};
*/


//Final

/*
struct Node {
    string word;
    int freq;
    Node* prev;
    Node* next;

    Node(string k) : word(k), freq(1), prev(nullptr), next(nullptr) {}
};

class AllOne {
public:
    Node *head, *tail;
    unordered_map<string, Node*> um;

    // for base connection join head and tail [ both are empty ]
    AllOne() {
        head = new Node("");
        tail = new Node("");
        head->next = tail;
        tail->prev = head;
    }

    // moving character to new node if its count increase
    void moveToCorrectNextPosition(Node* node) {
        Node* ptr = node->next;
        // checkig if any node exist with current frequency
        while (ptr != tail && node->freq > ptr->freq) {
            ptr = ptr->next;
        }

        if (ptr != node->next) {
            // remove node from current place
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // add it to new place before ptr
            ptr->prev->next = node;
            node->prev = ptr->prev;
            node->next = ptr;
            ptr->prev = node;
        }
    }

    // moving character to new node as its frequency decreased
    void moveToCorrectPrevPosition(Node* node) {
        Node* ptr = node->prev;
        // checkig if any node exist with current frequency
        while (ptr != head && node->freq < ptr->freq) {
            ptr = ptr->prev;
        }

        if (ptr != node->prev) {
            // remove node from current place
            node->prev->next = node->next;
            node->next->prev = node->prev;

            // add it to new place before ptr
            ptr->next->prev = node;
            node->next = ptr->next;
            node->prev = ptr;
            ptr->next = node;
        }
    }

    // increase the count of word
    void inc(string word) {
        if (um.find(word) != um.end()) {
            // already present -> update its count
            Node* node = um[word];
            node->freq++;

            // fix node position after upgrade
            moveToCorrectNextPosition(node);
        } 
        else {
            // create a new node
            Node* node = new Node(word);
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            // store it in map
            um[word] = node;

            // insert it into the list
            moveToCorrectNextPosition(node);
        }
    }

    void dec(string word) {
        Node* node = um[word];
        node->freq--;

        moveToCorrectPrevPosition(node);

        if (node->freq == 0) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            um.erase(word);
            delete node;
        }
    }

    string getMaxKey() {
        string ans = "";
        if (tail->prev != head)
            ans = tail->prev->word;
        return ans;
    }

    string getMinKey() {
        string ans = "";
        if (head->next != tail)
            ans = head->next->word;
        return ans;
    }
};
*/
