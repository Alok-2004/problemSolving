/*
1392. Longest Happy Prefix
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        vector<int>lps(s.size() , 0);
        int len = 0;
        for(int i = 1 ; i < s.size() ;){
            if(s[len] == s[i]){
                len++;
                lps[i] = len;
                i++;
            }else if(len){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
        return s.substr(0 , lps[s.size() - 1]);
    }
};

int main(){
	
}
