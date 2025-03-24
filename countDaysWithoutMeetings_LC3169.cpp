/*
3169. Count Days Without Meetings
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>&meets){
        
        vector<vector<int>>res;
        if(meets.size() == 0) return res;
        auto temp = meets[0];
        for(int i = 1 ; i < meets.size() ; i++){
            if(temp[1] < meets[i][0]){
                res.push_back(temp);
                temp = meets[i];
            }else{
                temp[1] = max(meets[i][1] , temp[1]);
            }
        }

        res.push_back(temp);
        return res;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());

        vector<vector<int>>temp = mergeIntervals(meetings);

        long long curr = 1;
        int res = 0;
        for(auto ele : temp){
            if(ele[0] > curr){
                res += (ele[0] - curr);
            }
            curr = ele[1] + 1;
        }

        if (curr <= days) res += (days - curr + 1);

        return res;

    }
};

int main(){
	
}
