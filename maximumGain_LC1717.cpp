#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a' && s[i] != 'b') continue;
            int j = i;
            string t = "";
            while (j < n && (s[j] == 'a' || s[j] == 'b')) {
                t += s[j];
                j++;
            }
            ans += max(processAB(t, x, y), processBA(t, x, y));
            i = j - 1;
        }
        return ans;
    }

    int processAB(string& s, int x, int y) {
        vector<char> stk;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && stk.back() == 'a' && s[i] == 'b') {
                stk.pop_back();
                ans += x;
            } else {
                stk.push_back(s[i]);
            }
        }
        int a = 0, b = 0;
        for (char c : stk) {
            if (c == 'a') a++;
            else b++;
        }
        return min(a, b) * y + ans;
    }

    int processBA(string& s, int x, int y) {
        vector<char> stk;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && stk.back() == 'b' && s[i] == 'a') {
                stk.pop_back();
                ans += y;
            } else {
                stk.push_back(s[i]);
            }
        }
        int a = 0, b = 0;
        for (char c : stk) {
            if (c == 'a') a++;
            else b++;
        }
        return min(a, b) * x + ans;
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
