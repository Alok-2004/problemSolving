class Solution {
public:
    int maxProfit(vector<int>& p) {
        int sz = p.size();
        int res = 0;
        for(int i = 1; i < sz; i++){
            if(p[i] > p[i - 1]){
                res = res + p[i] - p[i - 1];
            }
        }
        
        return res;
    }
};
