/*
1383. Maximum Performance of a Team
Solved
Hard
Topics
Companies
Hint
You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of its engineers' speeds multiplied by the minimum efficiency among its engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.
*/

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {efficiency[i], speed[i]};
        }
        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;

        for(auto [e, s] : v) {
            if(pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }
            sum += s;
            pq.push(s);
            ans = max(ans, sum * e);
        }

        return static_cast<int>(ans % MOD);
    }
};



