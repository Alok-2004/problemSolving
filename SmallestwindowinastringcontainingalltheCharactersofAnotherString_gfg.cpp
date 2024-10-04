/*
Smallest window in a string containing all the characters of another string
Given two strings s and p. Find the smallest window in the string s consisting of all the characters(including duplicates) of the string p.  
Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
	string smallestWindow (string s, string p){
		int len1 = s.size();
		int len2 = p.size();  // Reference point
		
		if(len1 < len2) return "-1";
		
		unordered_map<char , int>uM; // used to store char of s
		unordered_map<char , int>ref;
		
		for(char ele : p) ref[ele]++;
		
        int start = 0, count = 0, minLen = INT_MAX, startIndex = -1;

		for (int i = 0; i < len1; i++) {
            uM[s[i]]++;

            if (ref[s[i]] != 0 && uM[s[i]] <= ref[s[i]]){
            	count++;
        	}
            
            if (count == len2) {
                while (uM[s[start]] > ref[s[start]] || ref[s[start]] == 0) {
                    if (uM[s[start]] > ref[s[start]]) uM[s[start]]--;
                    start++;
                }

                int windowLen = i - start + 1;
                if (minLen > windowLen) {
                    minLen = windowLen;
                    startIndex = start;
                }
            }
        }
		
		if(Mstart != -1) return s.substr(startIndex , minLen);
		else return "-1";
	}
}; 
