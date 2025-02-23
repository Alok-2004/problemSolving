/*
Q3. Check If Digits Are Equal in String After Operations II
You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
Return true if the final two digits in s are the same; otherwise, return false.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(const string& str) {
        int len = static_cast<int>(str.size()), limit = len - 2, sum0 = 0, sum1 = 0;
        for (int i = 0; i <= limit; i++) {
            int val = binomMod10(limit, i);
            sum0 = (sum0 + val * (str[i] - '0')) % 10;
            sum1 = (sum1 + val * (str[i + 1] - '0')) % 10;
        }
        return sum0 == sum1;
    }

private:
    int binomMod10(int n, int k) {
        int mod2 = binomMod2(n, k), mod5 = binomMod5(n, k);
        for (int num = 0; num < 10; num++)
            if (num % 2 == mod2 && num % 5 == mod5) return num;
        return 0;
    }

    int binomMod2(int n, int k) {
        return ((n & k) == k) ? 1 : 0;
    }

    int binomMod5(int n, int k) {
        int comb[5][5] = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 1, 4, 1}}, res = 1;
        while (n > 0 || k > 0) {
            int nd = n % 5, kd = k % 5;
            if (kd > nd) return 0;
            res = (res * comb[nd][kd]) % 5;
            n /= 5; k /= 5;
        }
        return res;
    }
};

int main(){
	
}
