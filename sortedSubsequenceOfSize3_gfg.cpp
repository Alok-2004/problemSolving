/*
Sorted subsequence of size 3
You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {};
        
        stack<int> st;
        vector<int> mn(n, -1);
        vector<int> mx(n, -1);
        st.push(arr[0]);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                mn[i] = st.top();
            }
            st.push(arr[i]);
        }
        
        while (!st.empty()) {
            st.pop();
        }
        
        st.push(arr[n-1]);
        
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                mx[i] = st.top();
            }
            st.push(arr[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (mn[i] != -1 && mx[i] != -1) {
                return {mn[i], arr[i], mx[i]};
            }
        }
        
        return {};
    }
};

int main(){
	
}
