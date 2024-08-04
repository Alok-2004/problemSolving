#include<iostream>
using namepsace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(m + n);
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                res[k] = nums1[i];
                i++;
            } else {
                res[k] = nums2[j];
                j++;
            }
            k++;
        }

        while (i < m) {
            res[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n) {
            res[k] = nums2[j];
            j++;
            k++;
        }

        if ((m + n) % 2 == 1) {
            int mid = (m + n) / 2;
            return res[mid];
        } else {
            int mid1 = (m + n) / 2;
            int mid2 = mid1 - 1;
            return (res[mid1] + res[mid2]) / 2.0;
        }
    }
    
