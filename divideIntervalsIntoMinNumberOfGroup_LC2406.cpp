/*
2406. Divide Intervals Into Minimum Number of Groups
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] 
represents the inclusive interval [lefti, righti].
You have to divide the intervals into one or more groups such that each interval is in exactly one group, 
and no two intervals that are in the same group intersect each other.
Return the minimum number of groups you need to make.
Two intervals intersect if there is at least one common number between them. 
For example, the intervals [1, 5] and [5, 8] intersect.
*/

#include<bits/stdc++.h>
using namespace std;

//Time COmplexity of O(nlogn)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
       vector<int>st , end;
       for(auto ele : intervals){
            st.push_back(ele[0]);
            end.push_back(ele[1]);
       }

       sort(st.begin() , st.end());
       sort(end.begin() , end.end());

       int res = 0;
       int i = 0;
       int j = 0;
       int temp = 0;
       while(i < st.size() and j < end.size()){
            if(st[i] <= end[j]){
                i++;
                temp++;
            }else{
                j++;
                temp--;
            }
            res = max(temp , res);
       } 

       return res;
    }
};

// Using Priority Queue and Sorting
// TC of O(nlogn)
/*
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        priority_queue<int, vector<int>, greater<int>>minheap;

        minheap.push(intervals[0][1]);

        for(int i  = 1 ; i < intervals.size() ; i++){
            if(minheap.top() < intervals[i][0]){
                minheap.pop();
            }
            minheap.push(intervals[i][1]);    
        }

        return minheap.size();
    }
};
*/
int main(){
	
}
