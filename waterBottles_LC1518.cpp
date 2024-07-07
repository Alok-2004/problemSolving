class Solution {
public:
    int numWaterBottles(int n, int nE) {
        int res = n;

        while (n >= nE) {
            res += n / nE;
            n = (n / nE) + (n % nE);
        }

        return res;
    }
};
