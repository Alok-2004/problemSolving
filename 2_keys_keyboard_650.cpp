#include<iostream>
#include<vector>

using namespace std;

//DP solution
/*
class Solution {
public:
    int gd(int n){
        int res;
        for(int i = n/2 ; i >= 1 ; i--){
            if(n % i == 0){
                res = i;
                break;
            }
        }
        return res;
    }

    int solve(int n , vector<int>&dp){
        if(dp[n] != -1) return dp[n];
        int temp = gd(n);
        dp[n] = (n / temp) + solve( temp , dp);
        return dp[n]; 
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        vector<int>dp(n+1 , -1);
        dp[1] = 0;
        dp[2] = 2;
        return solve(n , dp);
    }
};
*/

int greatestDivisor(int n){
    for(int i = n/2; i>=1; i--){
        if(n % i == 0){
            return i;
        }
    }
    return 1;
}

int minSteps(int n){
    int count = 0;
    while( n > 1){
        int hf = greatestDivisor(n);
        count += (n/hf);
        n = hf;
    }
    return count;
}

int main(){
    int number = 20;
    cout<<minSteps(number);

    return 0;
}
