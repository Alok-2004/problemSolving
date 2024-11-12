/*
2501. Longest Square Streak in an Array
You are given an integer array nums. A subsequence of nums is called a square streak if:

The length of the subsequence is at least 2, and
after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array 
by deleting some or no elements without changing the order of the remaining elements.
*/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = -1;
        
        for(int num : nums) {
            int localMax = 1;

            int curr = sqrt(num);
            int temp = num;
            while(true){
                if(curr * curr != temp or !s.count(curr)) break;
                temp = curr;
                curr = sqrt(curr);
                localMax = localMax + 1;
            }
            res = max(localMax , res);
        }
        
        return res > 1 ? res : -1;
    }
};
*/

// Using DSU
class UnionFind {
public:
    unordered_map<int, int> parent, size;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    void add(int x) {
        if (!parent.count(x)) {
            parent[x] = x;
            size[x] = 1;
        }
    }
};

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        UnionFind uf;
        

        for (int num : nums) {
            uf.add(num);
            int sqrtNum = sqrt(num);
            if (sqrtNum * sqrtNum == num && s.count(sqrtNum)) {
                uf.add(sqrtNum);
                uf.unite(num, sqrtNum);
            }
        }
        
        int Max = -1;
        for (int num : nums) {
            int root = uf.find(num);
            Max = max(Max, uf.size[root]);
        }
        
        return Max > 1 ? Max : -1;
    }
};


int main(){
	
}
