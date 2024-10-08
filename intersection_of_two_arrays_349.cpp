#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int i = 0; // nums1
    int j = 0; // nums2

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    while(i < nums1.size() && j < nums2.size() ){
        if( (res.size() == 0) && ( nums1[i] == nums2[j] ) ){
            res.push_back(nums1[i]);
            i++;
            j++;
        }    
        else if( ( nums1[i] == nums2[j] ) && res[(res.size()-1)] != nums1[i]){
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if( nums1[i] > nums2[j])  j++;
        else  i++;
    }

    return res;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
