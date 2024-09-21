/*
241. Different Ways to Add Parentheses
Given a string expression of numbers and operators, return all possible results from computing all the 
different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
*/

#include<bits/stdc++.h>
using namespace std;


//solved using Recursion
/*
Time Complexity: O(n * 2^n).
Space Complexity: O(2^n) for storing the results, plus O(n) for the recursion stack.
*/
/*
class Solution {
public:
    vector<int> solve(string e) {
        vector<int>res;

        for(int i = 0 ; i < e.size() ; i++){
            if(e[i] == '*' or e[i] == '-' or e[i] == '+'){
                vector<int>left = solve(e.substr(0 , i));
                vector<int>right = solve(e.substr(i+1));

                for(auto l : left){
                    for(auto r : right){
                        if(e[i] == '*') res.push_back(l*r);
                        else if(e[i] == '+') res.push_back(l+r);
                        else res.push_back(l-r);
                    }
                }
            }
        }

        if(res.empty()){
            res.push_back(stoi(e));
        }
        return res;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
*/


// Memoization + recursion using Map
class Solution {
public:
    vector<int> solve(string e, unordered_map<string , vector<int>>&dp){
        if(dp.find(e) != dp.end()) return dp[e];

        vector<int>res;
        for(int i = 0 ; i < e.size() ; i++){
            if(e[i] == '*' or e[i] == '-' or e[i] == '+'){
                vector<int>left = solve(e.substr(0 , i) , dp);
                vector<int>right = solve(e.substr(i+1) , dp);

                for(auto l : left){
                    for(auto r : right){
                        if(e[i] == '*') res.push_back(l*r);
                        else if(e[i] == '-') res.push_back(l-r);
                        else res.push_back(l+r);
                    }
                }
            }
        }

        if(res.empty()) res.push_back(stoi(e));
        return dp[e] = res;
    }

    vector<int> diffWaysToCompute(string e) {
        unordered_map<string , vector<int>>dp;
        return solve(e, dp);
    }
};
