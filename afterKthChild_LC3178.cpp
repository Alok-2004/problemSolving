class Solution {
public:
    int numberOfChild(int n, int k) {
        if (k < n)   return k;
        int temp = (k % (2 * n - 2));
        if (temp < n) {
            return temp;
        } else {
            return 2 * n - 2 - temp;
        }
    }
};
