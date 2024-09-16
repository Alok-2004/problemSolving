/*
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int>st;
        st.push(-1);

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    res = max( res , i - st.top() );
                }
            }
        }

        return res;
    }
};

int main(){
	
}
