/*
239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/

#include<bits/stdc++.h>
using namespace std;

// Using Queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> dq;
        
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res[0] = nums[dq.front()];
        
        for(int i = k; i < n; i++) {
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            res[i - k + 1] = nums[dq.front()];
        }
        
        return res;
    }
};


// Time complexity n*klogk
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>>pq; // Max heap
        vector<int>res(n - k + 1 , 0);

        for(int i = 0; i < k ; i++){
            pq.push({nums[i] , i});
        }
        res[0] = pq.top().first;
        for(int i = 0 ; i <= n-k ; i++){
            pq.push({nums[i+k-1] , i+k-1});
            while(pq.top().second < i){
                pq.pop();
            }
            res[i] = pq.top().first;
        }
        return res;

    }
};
*/

int main(){
	
}
