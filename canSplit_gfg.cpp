/*
Split an array into two equal Sum subarrays
Given an array of integers arr, return true if it is possible to split it in 
two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. 
If it is not possible then return false.
*/
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        bool flag = false;
        for(int i = 1 ; i < arr.size() ;i++){
            arr[i] = arr[i] + arr[i-1];
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(2*arr[i] == arr.back()){
                flag = true;
                break;
            };
        }
        return flag;
    }
};

class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int leftSum = 0, rightSum = 0;
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            if (leftSum < rightSum) {
                leftSum += arr[left++];
            } else {
                rightSum += arr[right--];
            }
            if (leftSum == rightSum && left == right) {
                return true;
            }
        }

        return false;
    }
};
