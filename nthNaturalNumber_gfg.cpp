/*
Nth Natural Number
Given a positive integer n. 
You have to find nth natural number after removing all the numbers containing the digit 9.
*/
class Solution {
public:
    long long findNth(long long n) {
        long long result = 0, base = 1;
        while (n > 0) {
            result += (n % 9) * base;
            n /= 9;
            base *= 10;
        }
        return result;
    }
};
