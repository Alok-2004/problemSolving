/*
Sum of Middle elements of two sorted arrays
Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Examples:

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).
Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)
*/
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int low = 0, high = n;

        while (low <= high) {
            int i1 = (low + high) / 2;
            int i2 = n - i1;

            int l1, r1, l2, r2;

            if (i1 == 0) {
                l1 = INT_MIN;
            } else {
                l1 = arr1[i1 - 1];
            }

            if (i1 == n) {
                r1 = INT_MAX;
            } else {
                r1 = arr1[i1];
            }

            if (i2 == 0) {
                l2 = INT_MIN;
            } else {
                l2 = arr2[i2 - 1];
            }

            if (i2 == n) {
                r2 = INT_MAX;
            } else {
                r2 = arr2[i2];
            }

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2) + min(r1, r2);
            } else if (l1 > r2) {
                high = i1 - 1;
            } else {
                low = i1 + 1;
            }
        }

    }
};

