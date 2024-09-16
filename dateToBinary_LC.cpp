/*
Q1. Convert Date to Binary
You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.

date can be written in its binary representation obtained by converting year, month, and 
day to their binary representations without any leading zeroes and 
writing them down in year-month-day format.

Return the binary representation of date.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);
        
        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);
        
        string binaryYear = bitset<12>(y).to_string();
        string binaryMonth = bitset<4>(m).to_string();
        string binaryDay = bitset<5>(d).to_string();
        
        binaryYear = binaryYear.substr(binaryYear.find('1'));
        binaryMonth = binaryMonth.substr(binaryMonth.find('1'));
        binaryDay = binaryDay.substr(binaryDay.find('1'));

        return binaryYear + "-" + binaryMonth + "-" + binaryDay;
    }
};

