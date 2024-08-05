/*
2053. Kth Distinct String in an Array
A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. 
If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.
*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string res = "";
        unordered_map<string , int>uM;
        for( auto ele : arr ){
            uM[ele]++;
        }

        for(auto ele : arr){
            if(uM[ele] == 1){
                if(k == 1){
                    res = ele;
                    break;
                }else if( k > 1){
                    k--;
                }
            }
        }

        return res;
    }
};
