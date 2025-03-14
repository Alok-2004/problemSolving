/*
Decode the string
Given an encoded string s, the task is to decode it. The encoding rule is :

k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
Note: The test cases are generated so that the length of the output string will never exceed 105 .
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodedString(string &s) {
        stack<int> stn;
        stack<string> stc; 
        string res = "";
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) { 
                int count = 0;
                while (i < n && isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                i--; 
                stn.push(count);
            } 
            else if (s[i] == '[') {
                stc.push(res); 
                res = "";
            } 
            else if (s[i] == ']') {
                string temp = res;
                res = stc.top(); 
                stc.pop();
                
                int num = stn.top(); 
                stn.pop();
                
                while (num--) {
                    res += temp;
                }
            } 
            else {
                res += s[i];
            }
        }
        
        return res;
    }
};

int main(){
	
}
