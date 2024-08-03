/*
1460. Make Two Arrays Equal by Reversing Subarrays
You are given two integer arrays of equal length target and arr. 
In one step, you can select any non-empty subarray of arr and reverse it. 
You are allowed to make any number of steps.
Return true if you can make arr equal to target or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return is_permutation(arr.begin(), arr.end(), target.begin());
    }
};

int main(){
	
}
