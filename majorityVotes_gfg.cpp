/*
Majority Vote
You are given an array of integer nums[] where each number represents a vote to a candidate. 
Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size();
        
        int count1 = 0;
        int count2 = 0;
        int number1 = INT_MAX;
        int number2 = INT_MAX;
        vector<int>res;
        
        for(int i = 0 ; i < n ; i++){
            if(number1 == nums[i]) count1++;
            else if(number2 == nums[i]) count2++;
            else if(count1 == 0){
                number1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                number2 = nums[i];
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for(int i = 0 ; i< n; i++){
            if(nums[i] == number1) count1++;
            else if(nums[i] == number2) count2++;
        }
        
        if(count1 > n/3) res.push_back(number1);
        if(count2 > n/3) res.push_back(number2);
        
        if(not res.empty()) return res;
        else return {-1};
    }
};


int main(){
	
}
