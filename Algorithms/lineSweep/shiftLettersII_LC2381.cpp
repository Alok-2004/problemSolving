/*
2381. Shifting Letters II
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftDelta(n + 1, 0);

        // Mark the shifts in the difference array
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            shiftDelta[start] += (direction == 1 ? 1 : -1);
            shiftDelta[end + 1] -= (direction == 1 ? 1 : -1);
        }

        // Calculate prefix sum to get the net shifts at each index
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += shiftDelta[i];
            // Apply the shift to the character
            int newChar = ((s[i] - 'a') + netShift % 26 + 26) % 26;
            s[i] = 'a' + newChar;
        }

        return s;
    }
};

int main(){
	
}
