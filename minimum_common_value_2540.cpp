#include <iostream>
#include <vector>

using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int i = 0; // nums1
    int j = 0; // nums2
    while(i < nums1.size() && j < nums2.size()){
        if( nums1[i] == nums2[j]) return nums1[i];
        else if(nums2[j] > nums1[i])  i++;
        else  j++; 
    }
    return -1;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {4, 5, 6, 7, 8};
    
    int common = getCommon(nums1, nums2);
    
    if(common != -1) {
        cout << "Common element found: " << common << endl;
    } else {
        cout << "No common element found." << endl;
    }
    
    return 0;
}
