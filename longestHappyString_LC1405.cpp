/*
1405. Longest Happy String
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. 
If there are multiple longest happy strings, return any of them. 
If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string res = "";
        
        while (!pq.empty()) {
            auto [count1, char1] = pq.top();
            pq.pop();
            
            if (!res.empty() && res.back() == char1) {
                if (pq.empty()) break;
                
                auto [count2, char2] = pq.top();
                pq.pop();
                
                res += char2;
                if (--count2 > 0) {
                    pq.push({count2, char2});
                }
                pq.push({count1, char1});
            } else {
                int addCount = min(2, count1);
                res += string(addCount, char1);
                
                if (count1 - addCount > 0) {
                    pq.push({count1 - addCount, char1});
                }
            }
        }
        
        return res;
    }
};

int main(){

}
