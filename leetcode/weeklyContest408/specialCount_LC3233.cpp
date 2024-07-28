/*
Q2. Find the Count of Numbers Which Are Not Special
You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the proper divisors of x.
A number is called special if it has exactly 2 proper divisors. For example:
The number 4 is special because it has proper divisors 1 and 2.
The number 6 is not special because it has proper divisors 1, 2, and 3.
Return the count of numbers in the range [l, r] that are not special.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int specialCount = 0;

        int start = ceil(sqrt(l));
        int end = floor(sqrt(r));

        for (int i = start; i <= end; ++i) {
            if (isPrime(i)) {
                ++specialCount;
            }
        }

        int totalCount = r - l + 1;
        return totalCount - specialCount;
    }

private:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }
};
