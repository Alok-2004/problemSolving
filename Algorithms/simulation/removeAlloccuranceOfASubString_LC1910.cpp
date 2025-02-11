/*
1910. Remove All Occurrences of a Substring
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int len = part.size();
        char end = part.back();

        for (char ch : s) {
            res += ch;
            if (ch == end && res.size() >= len && res.substr(res.size() - len) == part) 
                res.erase(res.size() - len);
        }
        return res;
    }
};

int main(){
	
}
