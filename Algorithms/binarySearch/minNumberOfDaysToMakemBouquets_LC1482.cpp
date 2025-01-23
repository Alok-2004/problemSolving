/*
1482. Minimum Number of Days to Make m Bouquets
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(vector<int>& bloomDay, int m, int k , int mid){
        int count = 0;
        for(int i = 0 ; i < bloomDay.size() ; i++){
            if(bloomDay[i] <= mid){
                count++;
                if(count >= k) m-- , count = 0;
                if(m == 0) return true;
            }
            else count = 0;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if(static_cast<long long>(m)*k > bloomDay.size()) return -1;

        int right = *max_element(bloomDay.begin() , bloomDay.end());
        int left = 0;
        while(left < right){
            int mid = left + (right-left)/2;
            if(solve(bloomDay , m , k , mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
};

int main(){
	
}
