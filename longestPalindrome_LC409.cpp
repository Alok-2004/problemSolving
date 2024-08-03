/*
409. Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, 
return the length of the longest palindrome
that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char , int> uM;
        for( char ch : s){
            uM[ch]++;
        }

        bool oddFound = false;
        int res = 0;
        for( auto ele : uM){
            if( ele.second % 2 == 0 ) res += ele.second;
            else{
                res += ele.second - 1;
                oddFound = true;
            }
        }

        if( oddFound ){
            res++;
        }
        return res;
    }
};
