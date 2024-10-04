/*
2707. Extra Characters in a String
You are given a 0-indexed string s and a dictionary of words dictionary. 
You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. 
There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    unordered_map<int , int>uM;

    int solve(unordered_set<string>&uS , string &s , int idx){
        if(idx >= s.size()) return 0;
        if (uM.find(idx) != uM.end()) return uM[idx];

        int res = 1 + solve(uS , s , idx+1);
        string temp = "";
        for(int i = idx; i < s.size(); i++){
            temp = temp + s[i];
            if(uS.find(temp) != uS.end()){
                res = min(res , solve(uS , s , i+1));
            }
        }
        uM[idx] = res;
        return uM[idx];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>uS(dictionary.begin() , dictionary.end());
        int res = solve(uS , s , 0);
        return res;
    }
};

int main(){
	
}
