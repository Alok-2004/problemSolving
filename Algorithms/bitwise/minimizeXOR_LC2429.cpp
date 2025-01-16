/*
2429. Minimize XOR
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    void setBit(int &x, int bit) {
        x |= (1 << bit);
    }

    void unsetBit(int &x, int bit) {
        x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {

//    	first find number of set bits in num2
// 		if number of set bits is more than from num1 then simply unset the leat significat bit 
//		do same if number set bits is less from num1 then simply set the least significant bit
        int x = num1;
        int req = __builtin_popcount(num2);
        int curr = __builtin_popcount(x);
        int bit = 0;

        if (curr < req) {
            while (curr < req) {
                if (!isSet(x, bit)) {
                    setBit(x, bit);
                    curr++;
                }
                bit++;
            }
        } else {
            while (curr > req) {
                if (isSet(x, bit)) {
                    unsetBit(x, bit);
                    curr--;
                }
                bit++;
            }
        }

        return x;
    }
};


int main(){
	
}
