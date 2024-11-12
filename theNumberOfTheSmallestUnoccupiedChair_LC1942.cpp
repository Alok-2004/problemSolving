/*
1942. The Number of the Smallest Unoccupied Chair
There is a party where n friends numbered from 0 to n - 1 are attending. 
There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, 
they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and 
leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();
        int target = times[targetFriend][0];

        sort(times.begin(), times.end());
       
        priority_queue<int, vector<int>, greater<int>> avl;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> unavl;

        for(auto &i : times){

            while(!unavl.empty() && unavl.top().first<= i[0])
            {
                avl.push(unavl.top().second);
                unavl.pop();
            }

            if(i[0] == target) 
            {
                break;
            }

            if(avl.empty())
            {
                unavl.push({i[1], unavl.size()});
            }

            else
            {
                unavl.push({i[1], avl.top()});
                avl.pop();
            }
        }

        return avl.empty() ? unavl.size() : avl.top();
    }
};

int main(){
	
}
