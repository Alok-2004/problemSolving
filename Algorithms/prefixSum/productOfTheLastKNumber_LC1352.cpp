/*
1352. Product of the Last K Numbers
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.
*/

#include<bits/stdc++.h>
using namespace std;

// Linear Time Complexity
/*
class ProductOfNumbers {
    vector<int>nums;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int res = 1;
        for(int i = nums.size()-1 ; i >= 0 ,  k > 0; i-- , k--){
            res *= nums[i];
        }

        return res;
    }
};
*/

// Constant Time complexity
/*
class ProductOfNumbers {
    vector<int>nums;
    vector<int>zeroes;
public:
    ProductOfNumbers(){}
    
    void add(int num) {
        int n = nums.size();
        
        if(num == 0) {
            nums.push_back(1);
            zeroes.push_back(nums.size()-1);
        }else{
            if(n >= 1) nums.push_back(nums.back() * num);
            else nums.push_back(num);
        }
    }
    
    int getProduct(int k) {
        int n = nums.size();
        if (k > n) return 0;
        
        if (!zeroes.empty() && n - k <= zeroes.back() && zeroes.back() < n) {
            return 0;
        }
        
        if (k == n) return nums.back();
        return nums[n-1] / nums[n-k-1];  
    }
};
*/

int main(){
	
}
