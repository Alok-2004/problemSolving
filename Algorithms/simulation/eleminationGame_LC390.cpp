/*
390. Elimination Game
You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:

Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Given the integer n, return the last number that remains in arr.
*/

#include<bits/stdc++.h>
using namespace std;

// Failed Attempt
/*
class Solution {
public:
    vector<int> solve(vector<int> nums, bool flag) {
        if (nums.size() == 1) return nums;

        vector<int> res;
        if (flag) {
            for (int i = 0; i < nums.size(); i += 2) {
                
                res.push_back(nums[i]);
            }
        } else {
            for (int i = nums.size() - 1; i >= 0; i -= 2) {
                res.push_back(nums[i]);
            }
        }

        return solve(res, !flag);
    }

    int lastRemaining(int n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }

        vector<int> res = solve(nums, true);
        return res[0];
    }
};
*/

//using recursion



// Using iteration
class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n;
        int step = 1;
        int head = 1;

        while (remaining > 1) {
            if (left || remaining % 2 == 1) {
                head += step;
            }
            remaining /= 2;
            step *= 2;
            left = !left;
        }

        return head;
    }
};

class Solution {
public:
    int lastRemaining(int n) {
        
    }
};

int main(){
	
}
