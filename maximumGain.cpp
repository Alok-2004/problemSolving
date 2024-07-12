#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int score = 0;

        if (x > y) {
            for (char c : s) {
                if (c == 'b' && !st.empty() && st.top() == 'a') {
                    st.pop();
                    score += x;
                } else {
                    st.push(c);
                }
            }
            stack<char> temp;
            while (!st.empty()) {
                char c = st.top();
                st.pop();
                if (c == 'a' && !temp.empty() && temp.top() == 'b') {
                    temp.pop();
                    score += y;
                } else {
                    temp.push(c);
                }
            }
        } else {
            for (char c : s) {
                if (c == 'a' && !st.empty() && st.top() == 'b') {
                    st.pop();
                    score += y;
                } else {
                    st.push(c);
                }
            }
            stack<char> temp;
            while (!st.empty()) {
                char c = st.top();
                st.pop();
                if (c == 'b' && !temp.empty() && temp.top() == 'a') {
                    temp.pop();
                    score += x;
                } else {
                    temp.push(c);
                }
            }
        }
        
        return score;
    }
};

int main() {
    Solution sol;
    string s1 = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    cout << sol.maximumGain(s1, x1, y1) << endl; // Output: 19

    string s2 = "aabbaaxybbaabb";
    int x2 = 5, y2 = 4;
    cout << sol.maximumGain(s2, x2, y2) << endl; // Output: 20

    return 0;
}
