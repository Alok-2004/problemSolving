
// Using deque
/*
class Solution {
public:
    string reverseParentheses(string s) {
        deque<int> dq;
        vector<char> res;

        for (char char_s : s) {
            if (char_s == '(') {
                dq.push_back(res.size());
            } else if (char_s == ')') {
                int start_ind = dq.back();
                dq.pop_back();
                reverse(res.begin() + start_ind, res.end());
            } else {
                res.push_back(char_s);
            }
        }

        return string(res.begin(), res.end());
    }
};
*/

//Using stack

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                int si = st.top();
                reverse(s.begin() + si + 1, s.begin() + i);
                st.pop();
            }
            i++;
        }
        string res = "";
        for (auto ele : s) {
            if (ele != '(' && ele != ')') res += ele;  
        }
        return res;
    }
};
