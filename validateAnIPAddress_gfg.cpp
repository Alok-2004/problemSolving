/*
Validate an IP Address
Difficulty: MediumAccuracy: 11.22%Submissions: 249K+Points: 4
You are given a string str in the form of an IPv4 Address. Your task is to validate an IPv4 Address, 
if it is valid return true otherwise return false.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, 
each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1

A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255. 
Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255)

Note: Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        vector<string> parts;
        stringstream ss(str);
        string segment;
        
        while (getline(ss, segment, '.')){
			parts.push_back(segment);
		}
		
        if (parts.size() != 4) return false;
        for (const string& part : parts) {
            if (part.empty() || part.size() > 3) return false;
            if (!all_of(part.begin(), part.end(), ::isdigit)) return false;
            int num = stoi(part);
            if (num < 0 || num > 255) return false;
            if (to_string(num) != part) return false;
        }
        
        return true;
    }
};
