/*
2425. Bitwise XOR of All Pairings
You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int temp1 = 0;
        int temp2 = 0;
        for(int i = 0 ; i < nums1.size() ; i++){
            temp1 ^= nums1[i];
        }

        for(int i = 0 ; i < nums2.size() ; i++){
            temp2 ^= nums2[i];
        }

        return (nums1.size() % 2 ? temp2 : 0) ^ (nums2.size() % 2 ? temp1 : 0);
    }
};

int main(){
	
}
