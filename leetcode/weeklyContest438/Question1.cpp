/*
Q1. Check If Digits Are Equal in String After Operations I
You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
Return true if the final two digits in s are the same; otherwise, return false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string temp = "";
            for (int i = 0; i < s.length() - 1; i++) {
                int sum = (s[i] - '0' + s[i + 1] - '0') % 10;
                temp += to_string(sum);
            }
            s = temp;
        }
        
        return s[0] == s[1];
    }
};

int main(){
	
}
