#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int tar) {
        int n = arr.size();
        if (n < 3) return -1;
        sort(arr.begin(), arr.end());
        int closestSum = arr[0] + arr[1] + arr[2]; 
		for (int i = 0; i <= n - 3; i++) {
            int lp = i + 1;
            int rp = n - 1;
            while (lp < rp) {
                int currentSum = arr[i] + arr[lp] + arr[rp];
                if(abs(currentSum - tar) == abs(closestSum - tar)){
                    closestSum = max(closestSum, currentSum);
                }
                else if(abs(currentSum - tar) < abs(closestSum - tar)) {
                    closestSum = currentSum;
                }
                
                if (currentSum > tar) {
                    rp--;
                } else {
                    lp++;
                }
            }
        }
        return closestSum;
    }
};
