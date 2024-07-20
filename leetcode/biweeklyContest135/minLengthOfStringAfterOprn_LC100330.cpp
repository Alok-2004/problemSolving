/*
100330. Minimum Length of String After Operations
You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.
*/

class Solution {
public:
    int minimumLength(string s) {
        if(s.size() < 3) return s.size();
        unordered_map<char, int>uM;
        for( char ch : s){
            uM[ch]++;
        }

        int res = 0;

        for(auto x : uM){
            if(x.second == 3 ){
                res += 1;
            }else if( x.second == 1 || x.second == 2){
                res += x.second;
            }else{
                if(x.second % 2 == 0){
                    res += 2;
                }else{
                    res += 1;
                }
            }
        }

        return res;
    }
};
