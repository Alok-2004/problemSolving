/*
670. Maximum Swap
You are given an integer num. You can swap two digits at most once to get 
the maximum valued number.

Return the maximum valued number you can get.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // Calculate the number of digits in num
        int length = 0;
        int temp = num;
        while(temp > 0) {
            length++;
            temp = temp / 10;
        }

        // Convert num into a vector of digits (nums)
        vector<int> nums(length);
        temp = num;
        int i = length - 1;
        while(temp > 0) {
            int x = temp % 10;
            temp = temp / 10;
            nums[i] = x;
            i--;
        }

        // Use a stack to track the largest digit on the right of each index
        vector<int> v(length, -1);
        stack<int> st;

        // Traverse the digits from right to left to update the 'v' vector with the index of the largest right digit
        for(int i = length - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if(!st.empty()){
                v[i] = st.top();
            } else {
                st.push(i);
            }
        }
        
        // Try to swap the current digit with the largest available right-side digit
        bool flag = false;
        for(int i = 0; i < nums.size(); i++) {
            if(v[i] != -1 && nums[v[i]] != nums[i]) {
                swap(nums[i], nums[v[i]]);
                flag = true;
                break;
            }
        }

        // If no swap occurred, return the original number
        if(!flag) return num;

        // Reconstruct the number from the modified digits vector and return the result
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res = res * 10 + nums[i];
        }

        return res;
    }
};


int main(){
	
}
