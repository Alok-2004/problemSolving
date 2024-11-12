/*
Sub-arrays with equal number of occurences
he number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> balanceMap;
        balanceMap[0] = 1;  // Starting point, balance 0 is seen once
        int balance = 0;
        int result = 0;
        
        for (int num : arr) {
            if (num == x) balance++;
            else if (num == y) balance--;
            
            if (balanceMap.find(balance) != balanceMap.end()) {
                result += balanceMap[balance];
            }
            
			balanceMap[balance]++;
        }
        
        return result;
    }
};

int main(){
	
}
