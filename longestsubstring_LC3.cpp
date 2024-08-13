/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int>m;
        int i = 0 , j = 0;
        int res = 0;
        while( j < s.size()){
            if( m.find(s[j]) != m.end() and m[s[j]] >= i){
                i = m[s[j]] + 1;
                m[s[j]] = j;
            }else{
                m[s[j]] = j;
                res = max(res , j - i + 1);
            }
            j++;
        }
        return res;
    }
};
