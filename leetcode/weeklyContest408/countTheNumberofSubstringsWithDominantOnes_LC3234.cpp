/*
Q3. Count the Number of Substrings With Dominant Ones
You are given a binary string s.
Return the number of substrings with dominant ones.
A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.
*/


//Correct approach but TLE
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstringsWithDominantOnes(string s) {
        int res = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            int o = 0;
            int z = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    o++;
                } else {
                    z++;
                }
                if (o >= z * z) {
                    res++;
                }
            }
        }
        
        return res;
    }
};

//Wrong
/*
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int pre = 0;
        unordered_map<int , int>uM;
        uM[0]++;
        for( int i = s.size() - 1 ; i >= 0; i-- ){
            if(s[i] == '0'){
                pre += -1;
            }
            else{
                pre += 1;
            }

            int diff = pre - 0;
            if( uM[diff] >= 0){
                ans += uM[diff];
            }
            uM[diff]++;
        }

        return ans;
    }
};
*/
