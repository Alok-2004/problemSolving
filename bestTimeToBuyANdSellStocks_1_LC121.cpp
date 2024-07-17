// Using the concept of next greatest Element  TC O(n * n) 
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int sz = p.size();
        stack<int> st;
        int res = 0;
        for(int i = sz - 1; i >= 0; i--){
            if(st.empty()) st.push(p[i]);
            
            else if( st.top() > p[i]){
                res = max(res, st.top() - p[i]);
            }

            else{
                while(!st.empty() && st.top() <= p[i]){
                    st.pop();
                }

                st.push(p[i]);
            }
        }

        return res;
    }
};

// Normal Approach
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int sz = p.size();
        int res = 0;
        int mn = p[0];
        for(int i = 0; i < sz; i++){
            mn = min(mn, p[i]);
            res = max(res, p[i] - mn);
        }
        
        return res;
    }
};

