/*
556. Next Greater Element III
Given a positive integer n, find the smallest integer 
which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, 
if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int len = num.size();
        
        int i = len - 2;
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }
        
        if (i < 0) return -1;
        
        int j = len - 1;
        while (num[j] <= num[i]) {
            j--;
        }
        
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
        
        long long result = stoll(num);
        if (result > INT_MAX) return -1;
        
        return static_cast<int>(result);
    }
};

int main(){
	
}
