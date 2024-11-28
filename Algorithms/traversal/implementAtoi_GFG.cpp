/*
Implement Atoi
Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(char *s) {
        
        long long res = 0;
        int sign = 1;
        bool started = false;
        for(int i = 0; s[i] != '\0' ; i++){
            if(s[i] == ' ' and !started) continue;
            
            else if(s[i] == '-' and !started){ 
                sign = sign * -1;
            }
            
            else if (!started and s[i] >= '0' and s[i] <= '9'){
                started = true;
                res = res +  sign * (s[i] - '0');
            }
            
            else if(s[i] >= '0' and s[i] <= '9'){
                res = res * 10 + (s[i]-'0')*sign;
            }
            
            else{
                break;
            }
        }
        
        if(res > INT_MAX) res = INT_MAX;
        if(res < INT_MIN) res = INT_MIN;
        return res;
    }
};

int main(){
	
}
