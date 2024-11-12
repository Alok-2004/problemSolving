/*
2938. Separate Black and White Balls
There are n balls on a table, each ball has a color black or white.

You are given a 0-indexed binary string s of length n, 
where 1 and 0 represent black and white balls, respectively.

In each step, you can choose two adjacent balls and swap them.

Return the minimum number of steps to group all the black balls to the 
right and all the white balls to the left.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int white = 0;
        long long res = 0;
        int n = s.length();
        
        for (int j = 0; j < n; ++j) {
            if (s[j] == '0') {
                res += white;
            } else if (s[j] == '1') {
                white++;
            }
        }
        
        return res;
    }
};

int main(){
	
}
