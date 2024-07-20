class Solution {
  public:
    vector<int> constructLowerArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        multiset<int> sortedSet;
    
        for (int i = n - 1; i >= 0; --i) {
            sortedSet.insert(nums[i]);
            result[i] = distance(sortedSet.begin(), sortedSet.lower_bound(nums[i]));
        }
    
        return result;
    }
};
