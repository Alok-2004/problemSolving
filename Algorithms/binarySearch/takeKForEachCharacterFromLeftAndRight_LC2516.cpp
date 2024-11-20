/*
2516. Take K of Each Character From Left and Right
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. 
Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or 
return -1 if it is not possible to take k of each character.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    pair<bool, int> check(string &s, int k, int mid) {
        unordered_map<char, int> mp;
        int n = s.size();
        
        for (int i = 0; i < mid; i++) {
            mp[s[i]]++;
        }
        
        if (mp['a'] >= k && mp['b'] >= k && mp['c'] >= k) {
            return {true, mid};
        }

        bool flag = false;
        int temp = INT_MAX;

        for (int i = 1; i < n; i++) {
            mp[s[i - 1]]--;
            mp[s[(i + mid - 1 + n) % n]]++;

            if (mp['a'] >= k && mp['b'] >= k && mp['c'] >= k) {
                flag = true;
                if(n - (i + 1) < mid){
                    temp = 0;
                    break;
                }
                temp = min(temp, min(i, n - (i + mid)));
            }
        }

        return flag ? make_pair(true, mid + temp) : make_pair(false, INT_MAX);
    }

public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        cout<<s.size()<<endl;
        if (mp['a'] < k || mp['b'] < k || mp['c'] < k) {
            return -1;
        }

        int left = 0, right = s.size()+1;
        int res = INT_MAX;

        while (left < right) {
            int mid = left + (right - left) / 2;
            auto curr = check(s, k, mid);

            if (curr.first) {
                res = min(res, curr.second);
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};

int main(){
	
}
