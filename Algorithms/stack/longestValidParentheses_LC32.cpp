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
        stack<int>st;
        vector<int>temp(s.size() , 0);
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty() and s[i] == ')'){
                    temp[st.top()] = 1;
                    temp[i] = 1;
                    st.pop();
                }
            }
        }

        int res = 0;
        int count = 0;
        for(int i = 0 ; i < temp.size() ; i++){
            if(count+temp[i] != count+1){
                count  = 0;
            }else{
                count++;
                res = max(res , count);
            }
        }
        return res;
    }
};

int main(){
	
}
