/*
1433. Check If a String Can Break Another String
Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<int>&freq1 , vector<int>&freq2){
        int count = 0;
        for(int i = 0  ; i < 26 ; i++){
            count += freq1[i];
            count -= freq2[i];
            if (count < 0) return false;
        }
        return count >= 0;
    }

    bool checkIfCanBreak(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        
        for(int i = 0 ; i < s1.size() ; i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        return check(freq1 , freq2) || check(freq2 , freq1);
    }
};

// Also can be  solved using Sorting both the array

int main(){
	
}
