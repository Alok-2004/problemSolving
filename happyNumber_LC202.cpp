/*
202. Happy Number
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or 
it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int n){
        int res = 0;
        while(n > 0){
            int y = n%10;
            res += y*y;
            n = n/10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int>uS;
        int temp = n;
        bool flag = false;
        while(uS.find(temp) == uS.end()){
            uS.insert(temp);
            int curr = solve(temp);
            if(curr == 1){
                flag = true;
                break;
            }
            temp = curr;
        }

        return flag;
    }
};

int main(){
	
}
