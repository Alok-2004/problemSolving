/*
Q2. Count Almost Equal Pairs I
You are given an array nums consisting of positive integers.

We call two integers x and y in this problem almost equal if both integers can become equal after performing the following operation at most once:

Choose either x or y and swap any two digits within the chosen number.
Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.

Note that it is allowed for an integer to have leading zeros after performing an operation.
*/


//Was not able to solve some edge test cases missing
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int num1 = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int num2 = nums[j];
                
                if (num1 * 10 == num2 || num2 * 10 == num1) {
                    res++;
                    continue;
                }

                string s1 = to_string(num1);
                string s2 = to_string(num2);
                
                if (s1.size() != s2.size()) continue;
                
                vector<int> diff;
                for (int k = 0; k < s1.size(); k++) {
                    if (s1[k] != s2[k]) {
                        diff.push_back(k);
                    }
                }
                
                if (diff.size() == 2) {
                    swap(s1[diff[0]], s1[diff[1]]);
                    if (s1 == s2) {
                        res++;
                    }
                } else if (diff.size() == 0) {
                    res++;
                } else if (diff.size() == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
	
}
