/*
Split array in three equal sum subarrays
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. 
If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. 
The driver code will print true if it is correct otherwise, it will print false.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        int res = 0;
        for (auto ele : arr) {
            res += ele;
        }
        
        if (res % 3 != 0) return {-1, -1};
        int target = res / 3;
        
        int curr = 0, count = 0;
        vector<int> r(2, -1);
        for (int i = 0; i < arr.size(); i++) {
            curr += arr[i];
            if (curr == target) {
                count++;
                curr = 0;
                if (count == 1) r[0] = i;
                else if (count == 2) r[1] = i;
            }
        }
        
        if (count == 3) {
            return r;
        } else if(target == 0 and curr == 0){
            return r;
        }
        else return {-1, -1};
    }
};

int main(){
	
}
