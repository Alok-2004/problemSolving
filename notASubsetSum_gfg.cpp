/*
Not a subset sum
Given a sorted array arr[] of positive integers, find the smallest positive integer such that it cannot be 
represented as the sum of elements of any subset of the given array set.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        long long res = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > res) {
                break;
            }
            res += arr[i];
        }
        return res;
    }
};
int main(){
	
}
