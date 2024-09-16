/*
Longest valid Parentheses
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(string& str) {
        stack<int> st;
        int res = 0;
        st.push(-1);
        
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                
                if(st.empty()) {
                    st.push(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }
        
        return res;
    }
};

int main(){
}
