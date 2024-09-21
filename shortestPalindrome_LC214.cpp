/*
214. Shortest Palindrome
You are given a string s. You can convert s to a 
palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        //T.C : O(n^2)
        //S.C : O(n)
        for(int i = 0; i < s.length(); i++) {

            if(!memcmp(s.c_str(), rev.c_str() + i, s.length()-i)) { //prefix in s == suffix in rev
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }
};

int main(){
	
}
