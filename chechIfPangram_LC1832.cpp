/*
1832. Check if the Sentence Is Pangram
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, 
return true if sentence is a pangram, or false otherwise.
*/
class Solution {
public:
    bool checkIfPangram(string str) {
        if (str.length() < 26) return false;

        unordered_set<char> uM;
        for (char ch : str) {
            uM.insert(ch);
        }

        int s = uM.size();
        if (s == 26) return true;
        else  return false;
    }
};
