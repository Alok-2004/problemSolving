/*
Allocate Minimum Pages
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& arr, int n, int k, int mid) {
        int students = 1, pages = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) return false;
            if (pages + arr[i] > mid) {
                students++;
                pages = arr[i];
                if (students > k) return false;
            } else {
                pages += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(arr, n, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};

