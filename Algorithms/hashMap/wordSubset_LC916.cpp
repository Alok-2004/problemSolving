/*
916. Word Subsets
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.
*/

#inlclude<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isUniversal(const vector<int>& wordFreq, const vector<int>& maxFreq) {
        for (int i = 0; i < 26; ++i) {
            if (wordFreq[i] < maxFreq[i]) return false;
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            if (isUniversal(freq, maxFreq)) {
                result.push_back(word);
            }
        }

        return result;
    }

};

int main(){
}
