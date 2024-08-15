/*
860. Lemonade Change
At a lemonade stand, each lemonade costs $5. 
Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). 
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, 
return true if you can provide every customer with the correct change, or false otherwise.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int,int>cash;
        bool flag = true;
        for(int i = 0 ; i < bills.size() ; i++){
            
            if(bills[i] == 5) cash[5]++;
            
            else if(bills[i] == 10){
                if( cash.find(5) != cash.end() and cash[5] > 0 ){
                    cash[5]--;
                    cash[10]++;
                }else{
                    flag = false;
                    break;
                }
            }
            
            else{
                if(  cash.find(10) != cash.end() and cash.find(5) != cash.end() and cash[5] > 0 and cash[10] > 0 ){
                    cash[5]--;
                    cash[10]--;
                    cash[20]++;
                }
                else if(cash.find(5) != cash.end() and cash[5] >= 3){
                    cash[5] -= 3;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }

        return flag;
    }
};
