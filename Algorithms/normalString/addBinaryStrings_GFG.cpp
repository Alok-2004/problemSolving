/*
Add Binary Strings
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.
*/

#include<bits/stdc++.h>
using na,espace std;

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string res = "";
        int carry = 0;
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        while(i >= 0 and j >= 0){
            int temp = s1[i] - '0' + s2[j] - '0' + carry;
            int curr = temp % 2;
            res += to_string(curr);
            carry = temp / 2;
            i--;
            j--;
        }
        
        
        while (i >= 0) {
            int temp = s1[i] - '0' + carry;
            int curr = temp % 2;
            res += to_string(curr);
            carry = temp / 2;
            i--;
        }
        
        while (j >= 0) {
            int temp = s2[j] - '0' + carry;
            int curr = temp % 2;
            res +=to_string(curr)  ;
            carry = temp / 2;
            j--;
        }

        if (carry) {
            res += '1';
        }
        
        reverse(res.begin() , res.end());
        
        i  = 0 ;
        while(i <= res.size()-1){
            if(res[i] != '0'){
                res = res.substr(i);
                break;
            }
            i++;
        }
        
        return res;
    }
};

int main(){
	
}
