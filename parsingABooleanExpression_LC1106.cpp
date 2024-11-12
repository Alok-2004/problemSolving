/*
1106. Parsing A Boolean Expression
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    char solve(vector<char>&temp , char operation){
        if (operation == '!') {
            return temp[0] == 't' ? 'f' : 't';
        } else if (operation == '&') {
            for (char c : temp) {
                if (c == 'f') return 'f';
            }
            return 't';
        } else { // operation == '|'
            for (char c : temp) {
                if (c == 't') return 't';
            }
            return 'f';
        }
    }

    bool parseBoolExpr(string e) {
        int n = e.size();
        stack<char>st;

        for(int i = 0 ; i < n ; i++){
            if(e[i] == ',') continue;
            else if(e[i] != ')'){
                st.push(e[i]);
            }
            else{
                vector<char> temp;
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(temp , op));
            }
        }

        return st.top() == 't';
    }
};

int main(){
	
}
