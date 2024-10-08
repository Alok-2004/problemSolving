/*
Q1. Find the Key of the Numbers
You are given three positive integers num1, num2, and num3.

The key of num1, num2, and num3 is defined as a four-digit number such that:

Initially, if any number has less than four digits, it is padded with leading zeros.
The ith digit (1 <= i <= 4) of the key is generated by taking the smallest digit among the ith digits of num1, num2, and num3.
Return the key of the three numbers without leading zeros (if any).
*/
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        vector<int> res(4, 9);

        int i = 3;
        while (num1 > 0 || i >= 0) {
            res[i] = min(res[i], num1 % 10);
            num1 /= 10;n
            i--;
        }

        i = 3;
        while (num2 > 0 || i >= 0) {
            res[i] = min(res[i], num2 % 10);
            num2 /= 10;
            i--;
        }

        i = 3;
        while (num3 > 0 || i >= 0) {
            res[i] = min(res[i], num3 % 10);
            num3 /= 10;
            i--;
        }

        int ans = 0;
        for (i = 0; i <= 3; i++) {
            ans = ans * 10 + res[i];
        }

        return ans;
    }
};
