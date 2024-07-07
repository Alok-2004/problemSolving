class Solution {
public:
    int helper(int red, int blue, bool flag) {
        int count = 1;
        while (true) {
            if (flag) {
                if (red >= count) {
                    red -= count;
                    count++;
                    flag = !flag;
                } else
                    break;
            } else {
                if (blue >= count) {
                    blue -= count;
                    count++;
                    flag = !flag;
                } else
                    break;
            }
        }
        return count - 1;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue, true), helper(red, blue, false));
    }
};

