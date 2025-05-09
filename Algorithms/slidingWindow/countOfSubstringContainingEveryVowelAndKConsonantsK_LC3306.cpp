/*
3306. Count of Substrings Containing Every Vowel and K Consonants II
You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char, int> mp; 

        vector<int> nextCons(n);
        int lastConsIdx = n;
        //T.C : O(n)
        for(int i = n-1; i >=0; i--) {
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])) { 
                lastConsIdx = i;
            }
        }


        int i = 0;
        int j = 0;
        long long count = 0;
        int cons = 0;
        while(j < n) {
            char ch = word[j];
            if(isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            while(cons > k) {
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            while(i < n && mp.size() == 5 && cons == k) {
                int idx = nextCons[j];
                count += idx - j;
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};

int main(){
	
}
