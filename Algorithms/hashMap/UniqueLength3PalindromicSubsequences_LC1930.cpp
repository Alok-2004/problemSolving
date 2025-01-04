/*
1930. Unique Length-3 Palindromic Subsequences
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
*/

#include<bits/stdc++.h>
using namespace std;


// My Approach
/*
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> charCount(26, vector<int>(n + 1, 0));
        unordered_set<char> processed;
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                charCount[j][i + 1] = charCount[j][i];
            }
            charCount[s[i] - 'a'][i + 1]++;
        }

        for (int i = 0; i < n - 2; i++) {
            if (processed.count(s[i])) continue;
            processed.insert(s[i]);
            for (int j = n - 1; j > i + 1; j--) {
                if (s[i] == s[j]) {
                    int uniqueLetters = 0;
                    for (int k = 0; k < 26; k++) {
                        if (charCount[k][j] - charCount[k][i + 1] > 0) {
                            uniqueLetters++;
                        }
                    }
                    result += uniqueLetters;
                    break;
                }
            }
        }

        return result;
    }
};
*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char , vector<int>>mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]].emplace_back(i);
        }

        int ans = 0;
        for(auto ele : mp){
            vector<int>temp = ele.second;
            int st = temp[0];
            int end = temp.back();
            if(end - st <= 1) continue;
            unordered_set<char>seen;
            for(int i = st + 1 ; i < end ; i++){
                seen.insert(s[i]);
            }
            ans += seen.size();
        }
        return ans;
    }   
};

int main(){
	
}
