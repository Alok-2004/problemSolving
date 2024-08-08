/*
K-th element of two Arrays
Given two sorted arrays arr1 and arr2 and an element k. 
The task is to find the element that would be at the kth position of the combined sorted array.
*/
class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (k == 1) {
                if (arr1[i] < arr2[j]) res = arr1[i];
                else res = arr2[j];
                break;
            }
            k--;
            if (arr1[i] < arr2[j]) i++;
            else j++;
        }
        
        if (k > 1) {
            while (i < arr1.size()) {
                if (k == 1) {
                    res = arr1[i];
                    break;
                }
                k--;
                i++;
            }
            
            while (j < arr2.size()) {
                if (k == 1) {
                    res = arr2[j];
                    break;
                }
                k--;
                j++;
            }
        }
        return res;
    }
};


class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() > arr2.size()) {
            return kthElement(k, arr2, arr1);
        }
        
        int m = arr1.size();
        int n = arr2.size();
        
        int low = max(0, k - n);
        int high = min(m, k);
        
        while (low <= high) {
            int i = (low + high) / 2;
            int j = k - i;
            
            if (i < m && j > 0 && arr2[j - 1] > arr1[i]) {
                low = i + 1;
            } else if (i > 0 && j < n && arr1[i - 1] > arr2[j]) {
                high = i - 1;
            } else {
                int left1;
                if (i == 0) {
                    left1 = INT_MIN;
                } else {
                    left1 = arr1[i - 1];
                }

                int left2;
                if (j == 0) {
                    left2 = INT_MIN;
                } else {
                    left2 = arr2[j - 1];
                }

                int right1;
                if (i == m) {
                    right1 = INT_MAX;
                } else {
                    right1 = arr1[i];
                }

                int right2;
                if (j == n) {
                    right2 = INT_MAX;
                } else {
                    right2 = arr2[j];
                }

                return max(left1, left2);
            }
        }
        
        return -1;
    }
};

