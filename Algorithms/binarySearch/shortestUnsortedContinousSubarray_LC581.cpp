/*
581. Shortest Unsorted Continuous Subarray
Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.
*/

#include<bits/stdc++.h>
using namespace std;

// Will fail specially for [1,2,4,5,3]
// There we need another pass from last
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int initial = -1;
        int final = 0;
        stack<int> st;
        int i = 0;
        
        while (i < nums.size()) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                if (initial == -1) {
                    int j = st.top();
                    while (j > 0 && nums[j] == nums[st.top()]) {
                        j--;
                    }
                    
                    if (j >= 0 && nums[j] != nums[st.top()]) {
                        j++;
                    }
                    initial = j;
                    final = i;
                }
                else {
                    final = i;
                }
                cout<<"Initial "<<initial<<endl;
                cout<<"Final "<<final<<endl;
            }
            st.push(i);
            i++;
        }

        if (initial == -1) return 0;
        return final - initial + 1;
    }
};

int main(){

}
