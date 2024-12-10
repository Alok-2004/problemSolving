/*
2981 and 2982. Find Longest Special Substring That Occurs Thrice I and II
You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, int> charCount;
        for (char ele : s) charCount[ele]++;
        bool flag = false;
        for (auto ele : charCount) {
            if (ele.second >= 3) flag = true;
        }
        if (!flag) return -1;

        map<pair<char, int>, int> mp;
        int n = s.size(), res = 1;
        
        int i = 0;
        while (i < n) {
            char currentChar = s[i];
            int j = i;

            while (j < n && s[j] == currentChar) j++;
            
            int length = j - i;
            for (int len = 1; len <= length; len++) {
                mp[{currentChar, len}] += (length - len + 1);
            }


            i = j;
        }

        for (const auto& ele : mp) {
            if (ele.second >= 3) {
                res = max(res, ele.first.second);
            }
        }

        return res;
    }
};


int main(){
	
}
