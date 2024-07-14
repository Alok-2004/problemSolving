class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end(), greater<int>());
        sort(v.begin(), v.end(), greater<int>());

        int i = 0, j = 0;
        int nh = 1;
        int nv = 1;
        int res = 0;

        while (i < h.size() && j < v.size()) {
            if (h[i] > v[j]) {
                res += nv * h[i];
                i++;
                nh++;
            } else {
                res += nh * v[j];
                j++;
                nv++;
            }
        }

        while (i < h.size()) {
            res += nv * h[i];
            i++;
            nh++;
        }

        while (j < v.size()) {
            res += nh * v[j];
            j++;
            nv++;
        }

        return res;
    }
};

