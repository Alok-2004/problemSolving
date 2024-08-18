/*
Q2. Maximum Energy Boost From Two Drinks
You are given two integer arrays energyDrinkA and energyDrinkB of the same length n by a futuristic sports scientist. 
These arrays represent the energy boosts per hour provided by two different energy drinks, A and B, respectively.

You want to maximize your total energy boost by drinking one energy drink per hour. 
However, if you want to switch from consuming one energy drink to the other, you need to wait for one hour to cleanse your system 
(meaning you won't get any energy boost in that hour).

Return the maximum total energy boost you can gain in the next n hours.

Note that you can start consuming either of the two energy drinks.
*/
typedef long long ll;

class Solution {
public:
    ll maxEnergyBoost(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<ll> dpA(n), dpB(n);

        dpA[0] = A[0];
        dpB[0] = B[0];

        for (int i = 1; i < n; ++i) {
            dpA[i] = max(dpA[i-1] + A[i], dpB[i-1]);
            dpB[i] = max(dpB[i-1] + B[i], dpA[i-1]);
        }

        return max(dpA[n-1], dpB[n-1]);
    }
};

