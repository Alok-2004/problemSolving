/*
343. Integer Break
Given an integer n, break it into the sum of k positive integers, where k >= 2, 
and maximize the product of those integers.
Return the maximum product you can get. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1; 
        if (n == 3) return 2;

        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        product *= n; 
        return product;
    }
};

int main(){
	
}
