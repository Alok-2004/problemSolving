/*
Remove duplicates in array Specially for prime numbers
Given an array arr consisting of positive integer numbers, 
remove all duplicate numbers.
*/


// TC of O(n) and space is constant
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<int> removeDuplicate(vector<int> & arr){
		long long product = 1;
		vector<int>result;
		bool one = false;
		for(int i = 0 ; i < arr.size() ; i++){
			if(arr[i] == 1 and !one){
				result.push_back(1);
				one = true;
			}
			if(product % arr[i] == 0) continue;
			result.push_back(arr[i]);
			product *= arr[i];
		}
		
		return result;
	}
};

int main(){
	
}

