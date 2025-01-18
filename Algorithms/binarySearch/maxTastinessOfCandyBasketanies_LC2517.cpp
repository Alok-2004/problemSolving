/*
2517. Maximum Tastiness of Candy Basketanies
You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.

The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.

Return the maximum tastiness of a candy basket.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int mid, vector<int>& price, int k) {
        int count  = 1;
        int temp = price[0];
        for(int i = 1 ; i < price.size() ; i++){
            if(price[i] - temp >= mid){
                count++;
                temp = price[i];
            }
            if(count >= k) return true;
        }

        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int i = 0;
        int j = price.back() - price.front();
        while (i < j) {
            int mid = i + (j - i+1) / 2;
            if (solve(mid, price, k)) i = mid;
            else j = mid - 1;
        }
        return i;
    }
};

int main(){
	
}
