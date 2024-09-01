/*
Number of pairs
Given two positive integer arrays arr and brr, find the number of pairs such that x^y > y^x (raised to power of) 
where x is an element from arr and y is an element from brr.
*/
#include<bits/stdc++.h>
using namespace std;

//TC of O(n*m)
/*
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        long long count = 0;
        for (int x : arr) {
            for (int y : brr) {
                if (pow(x, y) > pow(y, x)) {
                    ++count;
                }
            }
        }
        return count;
    }
};
*/

/*
class Solution {
public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        vector<int> count(5, 0);
        for (int y : brr) {
            if (y < 5) count[y]++;
        }

        sort(brr.begin(), brr.end());
        long long totalPairs = 0;

        for (int x : arr) {
            if (x == 0) continue;
            if (x == 1) {
                totalPairs += count[0];
                continue;
            }

            auto idx = upper_bound(brr.begin(), brr.end(), x) - brr.begin();
            totalPairs += brr.size() - idx;
            totalPairs += count[1];

            if (x == 2) totalPairs -= (count[3] + count[4]);
            if (x == 3) totalPairs += count[2];
        }

        return totalPairs;
    }
};
*/

class Solution {
public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        long long res = 0;
        
        // Counters for specific values in brr
        int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
        for(int num : brr) {
            if(num == 0) count0++;
            if(num == 1) count1++;
            if(num == 2) count2++;
            if(num == 3) count3++;
            if(num == 4) count4++;
        }
        sort(brr.begin(), brr.end());
        sort(arr.begin(), arr.end());
        int j = 0;
        for(int x : arr) {
            if(x == 0) continue;
            
            if(x == 1) {
                res += count0;
            } else {
                res = res + count0 + count1;
                
                while(j < brr.size() && brr[j] <= x) {
                    j++;
                }
                res = res + brr.size() - j;
                
                if(x == 2) {
                    res = res - count3 - count4; 
                }
                if(x == 3) {
                    res += count2;
                }
            }
        }
        
        return res;
    }
};



int main(){
	
}
