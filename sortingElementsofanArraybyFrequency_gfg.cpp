/*
Sorting Elements of an Array by Frequency
Given an array of integers arr, sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. 
If the frequencies of two elements are the same, then the smaller number comes first.
*/

#include<bits/stdc++.h>
using namespace std;


//Using Max heap
/*
class Solution {
public:
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> uM;
        for (auto ele : arr) {
            uM[ele]++;
        }

        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
		
		for(auto ele : uM){
			pq.push( {ele.second , ele.first} );
		}
		
		vector<int> res;
		
		while(!pq.empty()){
			pair<int , int>p = pq.top();
			for(int i = 0 ; i < p.first; i++){
				res.push_back(p.second);
			}
			pq.pop();
		}
		
		return res;
    }
};
*/

//using Sorting
class Solution {
public:
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> uM;
        for (auto ele : arr) {
            uM[ele]++;
        }
        
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (freqMap[a] == freqMap[b])
                return a < b;
            return freqMap[a] > freqMap[b];
        });
        
        return arr;
    }
};

int main(){
	
}
