/*
K-Pangrams
Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, 
else return false.

A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.
*/
class Solution {
public:
    bool kPangram(string str, int k) {
        if (str.length() < 26) return false;

        unordered_set<char> uM;
        int l = 0;

        for (char ch : str) {
            if (ch == ' ') continue;
            uM.insert(ch);
            l++;
        }

        int s = uM.size();
        if (s == 26) return true;
        if (l < 26) return false;

        bool res = (26 - s) <= k;
        return res;
    }
};

