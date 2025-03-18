/*
2594. Minimum Time to Repair Cars
You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(long long mid , int cars , vector<int>&ranks){
        long long count = 0;
        for(int i = 0 ; i < ranks.size() ; i++){
            count += sqrt(1.0 * mid / ranks[i]);
        }

        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = *min_element(ranks.begin() , ranks.end());
        long long left = 1;
        long long right = 1LL * cars * cars * n;
        long long res = 0;
        while(left <= right){
            long long mid = left + ((right - left) / 2);
            if(solve(mid , cars , ranks)){
                res = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return res;
    }
};

int main(){
	
}
