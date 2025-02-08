/*
2349. Design a Number Container System
Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
*/

#include<bits/stdc++.h>
using namespace std;

/*
class NumberContainers {
public:
    unordered_map<int , int>primary; // index and number
    unordered_map<int , priority_queue<int , vector<int>, greater<int>> >sec;
    NumberContainers() {}
    
    void change(int index, int number) {
        primary[index] = number;
        sec[number].push(index);
        return;
    }
    
    int find(int number) {
        if(!sec.count(number)) return -1;
        auto pq = sec[number];
        int res = -1;
        while(!pq.empty()){
            int ele = pq.top();
            if(primary[ele] == number){
                return ele;
            }
            pq.pop();
        }
        return -1;
    }
};
*/

class NumberContainers {
public:
    unordered_map<int , int>primary; // index and number
    unordered_map<int , set<int> >sec;
    NumberContainers() {}
    
    void change(int index, int number) {
        if(primary.count(index)){
            int old = primary[index];
            sec[old].erase(index);
            if(sec[old].empty()) sec.erase(old);
        }
        primary[index] = number;
        sec[number].insert(index);
        return;
    }
    
    int find(int number) {
        if(!sec.count(number)) return -1;
        for(auto ele : sec[number]){
            return ele;
        }

        return -1;
    }
};

int main(){
	
}
