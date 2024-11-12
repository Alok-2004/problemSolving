/*
Minimum repeat to make substring
Given two strings s1 and s2. Return a minimum number of times s1 has to be 
repeated such that s2 is a substring of it. If s2 can never be a substring 
then return -1.

Note: Both the strings contain only lowercase letters.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string temp = s1;
        int res = 1;
        while(temp.size() < s2.size() + 2 * s1.size()){
            if(temp.find(s2) != string::npos){
                break;
            }
            
            temp += s1;
            res++;
        }
        
        if(temp.find(s2) != string::npos){
            return res;
        }else{
            return -1;
        }
    }
};
 

int main(){
	
}
