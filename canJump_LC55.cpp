#include<bits/stdc++.h>
using namespace std;


// Will not work n dont know why
/* 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int check = 0, i = 0;
        bool flag = false;
        int n = nums.size();
        while(true){
            if(i >= (n - 1)){
                flag = true;
                break;
            }
            check = i;
            cout<<i<< " "<< nums[i]<<endl;
            if( i == 0) i += nums[i];
            else i += nums[i - 1];

            if(check == i ){  // loop detected
                cout<<"Loop detected"<<endl;
                break;
            }
        }

        return flag;
    }
};
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return false;
    }
};



int main(){
	vector<int>nums = {3,2,1,0,4};
	Solution sl;
    bool res = sl.canJump(nums);
	cout<<res;
}
