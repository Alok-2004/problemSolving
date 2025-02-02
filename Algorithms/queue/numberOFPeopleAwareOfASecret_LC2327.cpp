/*
2327. Number of People Aware of a Secret
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

// Fails nad give TLE because of processing every single person will give time complexity of O(n * 2^(n/delay))
/*
#define MOD 1000000007
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int day = 1;
        long long personId = 1;
        queue<pair<long long, int>>q;
        q.push({1, 1});
        
        while(day < n){
            long long size = q.size();
            vector<pair<long long , int>>temp;
            while(size > 0 ){
                auto curr = q.front();
                q.pop();
                
                if(curr.second >= delay && curr.second < forget){
                    personId++;
                    temp.push_back({personId, 1});
                    curr.second++; 
                    temp.push_back(curr);
                }
                else if(curr.second <= delay){
                    curr.second++;
                    temp.push_back(curr); 
                }
                size--;
            }

            for(auto ele : temp){
                q.push(ele);
            }
            day++;
        }
        return q.size() % MOD;
    }
};
*/

// Now working on days wise and storing number of people on any given day
/*
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> count(forget + 1, 0);
        count[1] = 1;
        int days = 1;
        
        while(days < n) {
            long long sharing = 0;
            for(int i = forget - 1; i >= 1; i--) {
                if(i >= delay && i < forget) {
                    sharing = (sharing + count[i]) % MOD;
                }
                count[i + 1] = count[i];
            }
            
            count[1] = sharing;
            days++;
        }
        
        long long result = 0;
        for(int i = 1; i <= forget; i++) {
            result = (result + count[i]) % MOD;
        }
        
        return result;
    }
};
*/

int main(){
	
}
