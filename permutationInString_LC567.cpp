/*
567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a 
permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }
        int start = 0;
        int end = 0;
        while (end < s2.length()) {
            freq[s2[end] - 'a']--;
            while (freq[s2[end] - 'a'] < 0) {
                freq[s2[start] - 'a']++;
                start++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag && end - start + 1 == s1.length()) return true;
            end++;
        }
        return false;
    }
};


int main(){
	
}
