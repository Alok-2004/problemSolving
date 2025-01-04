/*
Count all triplets with given sum in sorted array
Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum < target) left++;
                else if (sum > target) right--;
                else {
                    int ele1 = arr[left], ele2 = arr[right], cnt1 = 0, cnt2 = 0;
                    while (left <= right && arr[left] == ele1) { left++; cnt1++; }
                    while (left <= right && arr[right] == ele2) { right--; cnt2++; }
                    res += (ele1 == ele2 ? cnt1 * (cnt1 - 1) / 2 : cnt1 * cnt2);
                }
            }
        }
        return res;
    }
};

int main(){
	
}
