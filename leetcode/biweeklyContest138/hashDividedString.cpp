/*
Q2. Hash Divided String
You are given a string s of length n and an integer k, where n is a multiple of k. Your task is to hash the string s into a new string called result, which has a length of n / k.

First, divide s into n / k 
substrings
, each with a length of k. Then, initialize result as an empty string.

For each substring in order from the beginning:

The hash value of a character is the index of that character in the English alphabet (e.g., 'a' ? 0, 'b' ? 1, ..., 'z' ? 25).
Calculate the sum of all the hash values of the characters in the substring.
Find the remainder of this sum when divided by 26, which is called hashedChar.
Identify the character in the English lowercase alphabet that corresponds to hashedChar.
Append that character to the end of result.
Return result.
*/

class Solution {
public:
    string stringHash(string s, int k) {
        string res = "";
        for(int i = 0; i < s.size(); ) {
            int c = 0;
            int temp = 0;
            while(c < k) {
                temp += (s[i] - 'a');
                i++;
                c++;
            }
            char hashedChar = 'a' + (temp % 26);
            res += hashedChar;
        }
        return res;
    }
};

