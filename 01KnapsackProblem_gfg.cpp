/*
0 - 1 Knapsack Problem
You are given weights and values of items, and put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.
In other words, given two integer arrays val and wt which represent values and weights associated with items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum sum values subset of val[] such that the sum of the weights of the corresponding subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item or don't pick it (0-1 property).
*/

#include<bits/stdc++.h>
using namespace std;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    	return a.first < b.first;
	}

class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
    	vector< pair<int , int> >p;
    	p.push_back({0 , 0});
    	for(int i = 0; i< wt.size() ; i++){
    		p.push_back( {wt[i] , val[i]});
		}
		
		sort(p.begin() , p.end() , comparePairs);
		
    	vector<vector<int> >dp(wt.size() + 1, vector<int>(W+1 , 0));
    	
    	for(int i = 1 ; i <= val.size() ; i++){
    		for(int j = 1 ; j <= W ; j++){
    			if(j >= p[i].first )  dp[i][j] = max(dp[i-1][j] , dp[i-1][j-p[i].first] + p[i].second);
    			else dp[i][j] = dp[i-1][j];
			}
		}
		
		return dp[val.size()][W];
	}
};

int main() {
    Solution sol;

    vector<int> weights1 = {4, 5, 1};
    vector<int> values1 = {1, 2, 3};
    int W1 = 4;

    int result1 = sol.knapSack(W1, weights1, values1);
    cout << "Maximum value in Knapsack (Example 1) = " << result1 << endl;

    vector<int> weights2 = {4, 5, 6};
    vector<int> values2 = {1, 2, 3};
    int W2 = 3;

    int result2 = sol.knapSack(W2, weights2, values2);
    cout << "Maximum value in Knapsack (Example 2) = " << result2 << endl;
    vector<int> weights3 = {2, 3, 4, 5};
    vector<int> values3 = {3, 4, 5, 6};
    int W3 = 5;

    int result3 = sol.knapSack(W3, weights3, values3);
    cout << "Maximum value in Knapsack (Additional test case) = " << result3 << endl;

    return 0;
}
