/*
3152. Special Array II
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
*/

// Brute Force WIll Give TLE
/*
class Solution {
public:

    bool solve(int i ,  int j , vector<int> &temp){
        int cur = temp[i];
        for(int k = i+1 ; k < temp.size() and k <= j ; k++){
            if(cur == temp[k]) return false;
            cur = temp[k];
        }
        return true;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& q) {
        vector<int>temp = nums;
        for(int i = 0 ; i < nums.size() ; i++){
            temp[i] = nums[i] % 2;
        }

        vector<bool>res(q.size());
        for(int i = 0 ; i < q.size() ; i++){
            res[i] = solve(q[i][0] , q[i][1] , temp);
        }

        return res;

    }
};
*/

// Using Cumulative sum

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
  		// In this approach first will make a array of size of n, where if arr[i] will show wheater it is is voilating the condition for special sub array
		int n = nums.size();
		vector<int>temp(n , 0);
		for(int i = 1 ; i < n ; i++){
			temp[i] = temp[i-1];
			if(nums[i] % 2 == nums[i-1] % 2){
				temp[i]++;
			}
		}  
		  
		// Now making the answer vector
		vector<bool>result(queries.size());
		for(int i = 0 ; i < queries.size() ; i++){
			result[i] = 0 == ( temp[ queries[i][1] ] - temp[ queries[i][0] ] );
		}
		return result;   
    }
};

// Using Binary Search

class Solution {
public:
	// Appling binary search
	bool solve(int left , int right , vector<int>&temp){
		int i = 0;
		int j = temp.size()-1;
		while(i <= j){
			int mid = i + ((j - i) / 2);
			if(temp[mid] < left){
				i = mid+1;
			}else if(temp[mid] > right){
				j = mid - 1;
			}else if(temp[mid] >= left and  temp[mid] <= right){
				
                cout<< mid <<endl;
                return false;
			}
		}
		return true;
	}

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
		// First will make a array where will store all the index with voilates the property of 
		// special array and later will use same for searching  check weather in the given query there exist any voilating index
		
		int n = nums.size();
		vector<int>temp;
		for(int i = 1 ; i < n; i++){
			if( (nums[i-1] % 2) == (nums[i] % 2) ) {
                temp.emplace_back(i);
            }
		}
		
		// now searching in the array for possible array using binary Search
		vector<bool>res;
		for(auto y : queries){
			bool x = solve(y[0]+1 , y[1] , temp);
			res.emplace_back(x);
		}
		
		return res;	
	}
};

itnm main(){
	
}
