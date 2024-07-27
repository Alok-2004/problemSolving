/*
415. Add Strings
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
You must also not convert the inputs to integers directly.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            carry = sum / 10;
            result += to_string(sum % 10);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//Will fail because the a + b will axceed long long range
/*
class Solution {
public:
    string addStrings(string num1, string num2) {
        long long a = 0;
        long long b = 0;
        for(int i  = 0; i< num1.size(); i++){
            a = a * 10 + num1[i] - '0';
        }

        for(int i  = 0; i< num2.size(); i++){
            b = b * 10 + num2[i] - '0';
        }

        a = a + b;
        return "" + to_string(a);
    }
};
*/

int main(){
	Solution s;
	string a = "2345654667678";
	string b = "65456789";
	string c = "";
	c += s.addStrings(a, b);
	cout<<c;
}
