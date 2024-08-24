/*
564. Find the Closest Palindrome
Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. 
If there is a tie, return the smaller one.
The closest is defined as the absolute difference minimized between two integers.
*/

#include<bits/stdc++.h>
using namespace std;

//was not able to think all the edge test cases
/*
class Solution {
public:

    bool isPalindrome(string nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] != nums[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string nearestPalindromic(string nums) {
        int size = nums.size();

        if (size == 1) {
            return nums == "0" ? "1" : to_string(stoi(nums) - 1);
        }

        char left = '\0';
        int secondStart;
        if (size % 2 == 0) {
            secondStart = size / 2;
        } else {
            left = nums[size / 2];
            secondStart = size / 2 + 1;
        }

        string firstHalf = nums.substr(0, size / 2);
        string secondHalf = nums.substr(secondStart, size - secondStart);
        reverse(secondHalf.begin(), secondHalf.end());
        int first = stoi(firstHalf);
        int sec = stoi(secondHalf);
        string res = "";

        if (first < sec) {
            res = firstHalf;
            if (left != '\0') res += left;
            reverse(firstHalf.begin(), firstHalf.end());
            res += firstHalf;
        } else {
            res = secondHalf;
            if (left != '\0') res += left;
            reverse(secondHalf.begin(), secondHalf.end());
            res += secondHalf;
        }

        return res;
    }
};
*/

//Approach (Using simple observation)
//T.C : O(n)
//S.C : O(1) //Ignoring space taken during string copy internally
class Solution {
public:
    long halfToPalindrome(long left, bool even) {
        long resultNum = left;
        if (!even) {
            left = left / 10;
        }

        while (left > 0) {
            int digit = left % 10;
            resultNum = (resultNum * 10) + digit;
            left /= 10;
        }
        return resultNum;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        int mid = len / 2;
        long firstHalf = stol(n.substr(0, len % 2 == 0 ? mid : mid + 1));
        /*
          Generate possible palindromic candidates:
          1. Palindrome by mirroring the first half.
          2. Palindrome by mirroring the first half + 1.
          3. Palindrome by mirroring the first half - 1.
          4. Handle edge cases by considering palindromes of the form 999...
             and 100...001

          I was not able to catch the 3rd and 4th edge case :-( . But it's ok , I got to learn something.
        */
        vector<long> possibleResults;
        possibleResults.push_back(halfToPalindrome(firstHalf, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        possibleResults.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        possibleResults.push_back((long)pow(10, len - 1) - 1);
        possibleResults.push_back((long)pow(10, len) + 1);

        long diff         = LONG_MAX;
        long result       = 0;
        long originalNum  = stol(n);

        for (long &num : possibleResults) {
            if (num == originalNum) continue;
            if (abs(num - originalNum) < diff) {
                diff = abs(num - originalNum);
                result = num;
            } else if (abs(num - originalNum) == diff) {
                result = min(result, num);
            }
        }

        return to_string(result);
    }
};


int main(){
	
}
