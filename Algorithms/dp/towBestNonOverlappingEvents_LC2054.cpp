/*
2054. Two Best Non-Overlapping Events
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.
*/
#include<bits/stdc++.h>
using namespace std;

// TLE
/*
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int>(3, -1)); 
        return solve(0, 0, dp, events);
    }

    int solve(int i, int picked, vector<vector<int>>& dp, vector<vector<int>>& events) {
        if (i >= events.size()) return 0;
        if (dp[i][picked] != -1) return dp[i][picked];

        int temp = solve(i + 1, picked, dp, events);

        if (picked < 2) {
            temp = max(temp, events[i][2] + solve(findNext(i, events), picked + 1, dp, events));
        }

        dp[i][picked] = temp;
        return temp;
    }

    int findNext(int i, vector<vector<int>>& events) {
        for (int j = i + 1; j < events.size(); ++j) {
            if (events[j][0] > events[i][1]) return j; // Find the next non-overlapping event
        }
        return events.size();
    }
};
*/

class Solution {
public:
    int n;
    int dp[100001][3];
    
    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0;
        int r = n-1;
        int result = n;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(events[mid][0] > endTime) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>& events, int i, int count) {
        if(count == 2 || i >= n) {
            return 0;
        }

        if(dp[i][count] != -1) {
            return dp[i][count];
        }

        int nextValidEventIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidEventIndex, count+1);

        int not_take = solve(events, i+1, count);

        return dp[i][count] = max(take, not_take);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(begin(events), end(events));
        memset(dp, -1, sizeof(dp));

        int count = 0;
        return solve(events, 0, count);
    }
};

int main(){
	
}
