/*
Q2. K-th Nearest Obstacle Queries
There is an infinite 2D plane.

You are given a positive integer k. You are also given a 2D array queries, which contains the following queries:

queries[i] = [x, y]: Build an obstacle at coordinate (x, y) in the plane. It is guaranteed that there is no obstacle at this coordinate when this query is made.
After each query, you need to find the distance of the kth nearest obstacle from the origin.

Return an integer array results where results[i] denotes the kth nearest obstacle after query i, or results[i] == -1 if there are less than k obstacles.

Note that initially there are no obstacles anywhere.

The distance of an obstacle at coordinate (x, y) from the origin is given by |x| + |y|.
*/
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        vector<int> res;
        priority_queue<int> mH;
        
        for (auto ele : q) {
            int x = ele[0];
            int y = ele[1];
            int distance = abs(x) + abs(y);
            
            mH.push(distance);
            
            if (mH.size() > k) {
                mH.pop();
            }
            
            if (mH.size() < k) {
                res.push_back(-1);
            } else {
                res.push_back(mH.top());
            }
        }
        
        return res;
    }
};

