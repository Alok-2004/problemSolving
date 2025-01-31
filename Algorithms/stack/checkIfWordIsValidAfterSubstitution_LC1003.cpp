/*
1003. Check If Word Is Valid After Substitutions
Given a string s, determine if it is valid.

A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0, n = s.size();
        
        while (i < n) {
            if (s[i] == 'c') {
                if (st.empty() || st.top() != 'b') return false;
                st.pop();
                if (st.empty() || st.top() != 'a') return false;
                st.pop();
            } else {
                st.push(s[i]);
            }
            i++;
        }
        
        return st.empty();
    }
};

int main(){
	
}
