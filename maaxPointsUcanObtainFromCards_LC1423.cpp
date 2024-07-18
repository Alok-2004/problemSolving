/*
1423. Maximum Points You Can Obtain from Cards
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/

class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += c[i];
        }
        
        int res = sum;
        for(int i = k - 1, j = c.size() - 1; i >= 0; i--, j--){
            sum -= c[i];
            sum += c[j];
            res = max( res, sum );
        }

        return res;
    }
};
