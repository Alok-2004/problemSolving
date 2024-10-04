/*
2491. Divide Players Into Teams of Equal Skill
You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. 
Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

The chemistry of a team is equal to the product of the skills of the players on that team.

Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players 
into teams such that the total skill of each team is equal.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long pre = 0;
        for(auto ele : skill) pre += ele;

        if(pre % (n/2) != 0) return -1;
        unordered_map<int , int> uM;

        for(auto ele : skill) {
            uM[ele]++;
        }

        int k = pre / (n/2);
        long long res = 0;

        for(auto x : uM) {
            int y = x.first;
            int diff = k - y;
            if(diff < -1) return -1;
            uM[y]--;
            if(uM.find(diff) != uM.end()) {
                uM[diff]--;
                res += diff * y;
            } else {
                return -1;
            }
        }

        return res;
    }
};

int main(){
	
}
