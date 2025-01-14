

/**
 * Find the Prefix Common Array of Two Arrays
 * 
 * Given two arrays A and B of length n, both containing integers from 1 to n,
 * the task is to find their prefix common array C where:
 * C[i] is the count of numbers that are present at or before index i in both A and B.
 * 
 * Example:
 * Input: A = [1,3,2,4], B = [3,1,2,4]
 * Output: [0,2,3,4]
 * Explanation:
 * i=0: No numbers are common, C[0] = 0
 * i=1: 1 and 3 are common, C[1] = 2
 * i=2: 1, 2, and 3 are common, C[2] = 3
 * i=3: 1, 2, 3, and 4 are common, C[3] = 4
 * 
 * Constraints:
 * - 1 <= n <= 100
 * - 1 <= A[i], B[i] <= n
 * - A and B are permutations of [1,2,...,n]
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>res(A.size() , 0);
        unordered_map<int , int>mp;
        mp[A[0]]++;
        mp[B[0]]++;
        if(mp[A[0]] == 2) res[0] = 1;
        for(int i = 1 ; i < A.size() ; i++){
            int count = 0;
            mp[A[i]]++;
            mp[B[i]]++;
            if(mp[A[i]] >= 2) count++;
            if(A[i] != B[i] and mp[B[i]] >= 2) count++;
            res[i] += res[i-1] + count; 
        }

        return res;
    }
};

int main(){

}