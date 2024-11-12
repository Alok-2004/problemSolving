/*
2463. Minimum Total Distance Traveled
There are some robots and factories on the X-axis. You are given an integer array robot where 
robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory 
and that the jth factory can repair at most limitj robots.

The positions of each robot are unique. The positions of each factory are also unique. 
Note that a robot can be in the same position as a factory initially.

All the robots are initially broken; they keep moving in one direction. 
The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.

At any moment, you can set the initial direction of moving for some robot. 
Your target is to minimize the total distance traveled by all the robots.

Return the minimum total distance traveled by all the robots. 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int rob , int fi , vector<int>& robot , vector<int>& fidx , vector<vector<long long>>&dp){
        if(rob >= robot.size()) return 0;
        if(fi >= fidx.size()) return LLONG_MAX - INT_MAX;
        if(dp[rob][fi] != -1 ) return dp[rob][fi]; 

        long long localMin = abs(robot[rob] - fidx[fi]) + solve(rob + 1 , fi + 1 , robot , fidx , dp);
        
        localMin = min(localMin, solve(rob , fi + 1 , robot , fidx , dp));
        return dp[rob][fi] = localMin;
        
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin() , robot.end());
        sort(factory.begin() , factory.end());

        vector<int>fidx;
        for(int i = 0 ; i < factory.size() ; i++){
            int k = factory[i][1];
            while(k > 0){
                fidx.push_back(factory[i][0]);
                k--;
            }
        }
        vector<vector<long long>>dp(robot.size() + 1 , vector<long long>(fidx.size() + 1, -1));
        long long result = solve(0 , 0 , robot , fidx , dp);
        return result;
    }
};

int main(){
	
}
