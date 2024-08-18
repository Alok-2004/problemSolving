/*
Q1. Count Substrings That Satisfy K-Constraint I
You are given a binary string s and an integer k.

A binary string satisfies the k-constraint if either of the following conditions holds:

The number of 0's in the string is at most k.
The number of 1's in the string is at most k.
Return an integer denoting the number of 
substrings
 of s that satisfy the k-constraint.
*/
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            int countZero = 0, countOne = 0;
            
            for (int j = i; j < n; ++j) {
                if (s[j] == '0') {
                    ++countZero;
                } else {
                    ++countOne;
                }
                
                if (countZero <= k || countOne <= k) {
                    ++result;
                } else {
                    break;
                }
            }
        }
        
        return result;
    }
};

