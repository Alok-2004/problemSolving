/*
1492. The kth Factor of n
You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.
*/
#include<bits/stdc++.h>
using namespace std;

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int kthFactor(int n, int k) {
		int res = -1;
  		vector<int>temp;
		for(int i = 1; i * i <= n; i++ ){
			if( n % i == 0){
				temp.push_back(i);
				if( i*i == n) continue;
				else{
					temp.push_back(n / i);
				}
			}
		}
		sort(temp.begin(), temp.end());
		if( k <= temp.size()){
			res = temp[k - 1];
		}
		return res;
    }
};

int main(){
	int k = 6;
	int n = 2434;
	Solution s;
	int res = s.kthFactor(n, k);
	cout<<res;
}
