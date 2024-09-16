/*
539. Minimum Time Difference
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
*/

#include<bits/stdc++.h>
using namespace std;

// TC =  nlogn SC = n
/*
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes(timePoints.size());
        
        for (int i = 0; i < timePoints.size(); ++i) {
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3));
            minutes[i] = h * 60 + m;
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < minutes.size() - 1; ++i) {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }

        minDiff = min(minDiff, 24 * 60 - minutes.back() + minutes.front());

        return minDiff;
    }
};
*/

//Fill bucket 
class Solution{
public:
	
	int solve(string s) {
		int hr = stoi(s.substr(0, 2));
		int min = stoi(s.substr(3));
		
		return min + hr * 60;
	}
	
	int findMinDifference(vector<string>& tp) {
		vector<bool> temp(1440, false);
		
		for(auto ele : tp) {
			int curr = solve(ele);
			if(!temp[curr]) temp[curr] = true;
			else return 0;
		}
		
		int res = INT_MAX;
		int x = INT_MIN;
		int first = 0;
		int last = 0;
		
		for(int i = 0; i < 1440; i++) {
			if(temp[i] && x == INT_MIN) {
				x = i;
				first = i;
			} else if(temp[i]) {
				res = min(res, i - x);	
				x = i;
				last = i;
			}
		}
		
		res = min(res, 1440 - last + first);
		
		return res;
	}
};

