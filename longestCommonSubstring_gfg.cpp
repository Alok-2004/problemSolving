/*
Longest Common Substring
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }
};

int main(){
	string s1 = "bbsbfdbfdsbs";
	string s2 = "hjbvdfdbfsskvhdf";
	Solution s;
	int n = s.longestCommonSubstr(s1 , s2);
	cout<<n;
}
