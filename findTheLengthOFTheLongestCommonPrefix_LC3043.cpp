/*
3043. Find the Length of the Longest Common Prefix
You are given two arrays with positive integers arr1 and arr2.
A prefix of a positive integer is an integer formed by one or more of its digits, 
starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. 
For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.
You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.
Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.
*/
#include<bits/stdc++.h>
using namespace std;

// TLE
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>uS;

        for(int i = 0 ; i < arr1.size() ; i++){
            string temp = to_string(arr1[i]);
            string curr = "";
            for(int j = 0; j < temp.size() ; j++){
                curr += temp[j];
                uS.insert(curr);
            }
        }

        int res = 0;;
        for(int i = 0 ; i < arr2.size() ; i++){
            string temp = to_string(arr2[i]);
            string curr = "";
            for(int j = 0; j < temp.size() ; j++){
                curr += temp[j];
                if( uS.find(curr) != uS.end() ){
                    int k = curr.size();
                    res = max(res , k);
                }
            }
        }

        return res;
    }
};

int main(){
	
}
