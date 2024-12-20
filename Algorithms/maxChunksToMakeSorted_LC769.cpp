/*
769. Max Chunks To Make Sorted
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
*/

#include<bits/stdc++.h>
using namespace std;

// My approach
/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> minVec(n + 1, INT_MAX);

        for (int i = n - 1; i >= 0; i--) {
            minVec[i] = min(arr[i], minVec[i + 1]);
        }

        int res = 0;
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) {
            mx = max(mx, arr[i]);
            if (mx <= minVec[i + 1]) {
                res++;
            }
        }
        return res;
    }
};
*/

// stack
/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int num : arr) {
            int maxInChunk = num;
            while (!st.empty() && st.top() > num) {
                maxInChunk = max(maxInChunk, st.top());
                st.pop();
            }
            st.push(maxInChunk);
        }
        return st.size();
    }
};

*/

// Better Approach
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, maxElement = 0;
        for (int i = 0; i < n; i++) {
            maxElement = max(maxElement, arr[i]);

            if (maxElement == i) {
                chunks++;
            }
        }

        return chunks;
    }
};

int main(){
	
}
