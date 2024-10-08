/*
Minimum number of deletions and insertions
Given two strings str1 and str2. The task is to remove or insert the minimum 
number of characters from/in str1 so as to transform it into str2. 
It could be possible that the same character needs to be removed/deleted 
from one point of str1 and inserted to some another point.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int lcsLength = dp[n][m];
        return (n - lcsLength) + (m - lcsLength);
    }
};

int main(){
	
}

