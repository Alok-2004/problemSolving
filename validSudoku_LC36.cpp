#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	typedef unordered_map<char, bool> uM;
	bool isValidSudoku(vector<vector<char> >& nums){
		vector<uM> c(9);
		vector<uM> r(9);
		vector<uM> b(9);
		bool flag = true;

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(nums[i][j] != '.'){
					char ch = nums[i][j];
					int block = (i / 3) * 3 + (j / 3);
					
                    if(c[j][ch] || r[i][ch] || b[block][ch]){
						flag = false;
						break;
					}
					
                    c[j][ch] = true;
					r[i][ch] = true;
					b[block][ch] = true;
				}
			}
		}
		return flag;
	}
};

int main
