/*
Minimum sum
Given an array arr[] such that each element is in the range [0 - 9], 
find the minimum possible sum of two numbers formed using the elements of the array. All digits 
in the given array must be used to form the two numbers. Return a string without leading zeroes.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(const string &num1, const string &num2) {
        string result;
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        
        int pos = 0;
        while (pos < result.size() && result[pos] == '0') pos++;
        
        return pos == result.size() ? "0" : result.substr(pos);
    }

    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string number1, number2;

        for (int i = 0; i < arr.size(); ++i) {
            if (i % 2 == 0)
                number1 += to_string(arr[i]);
            else
                number2 += to_string(arr[i]);
        }

        return addStrings(number1, number2);
    }
};
