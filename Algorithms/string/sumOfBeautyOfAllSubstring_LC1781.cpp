/*
1781. Sum of Beauty of All Substrings
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto it : mp) {
                    maxFreq = max(maxFreq, it.second);
                    minFreq = min(minFreq, it.second);
                }
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};

int main(){
	
}
