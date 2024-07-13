// Robot collision 2751
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& hlt, string drc) {
        map<int, int> pm; // pos, indx
        
        for(int i = 0; i < pos.size(); i++) {
            pm.insert({pos[i], i});
        }
        
        stack<int> st; // will store index
        
        for(auto x : pm) {
            if(st.empty()) {
                st.push(x.second);        
            }else{
                int idx = st.top();
                bool flag  = true;
                while(!st.empty() && drc[idx] == 'R' && drc[x.second] == 'L') {
                    if(hlt[idx] == hlt[x.second]) {
                        st.pop();
                        flag = false;;
                        break;
                    } else if(hlt[idx] > hlt[x.second]) {
                        hlt[idx]--;
                        break;
                    } else {
                        st.pop();
                        hlt[x.second]--;
                        if(!st.empty()) {
                            idx = st.top();
                        }
                    }
                }
                
                if( (flag && st.empty()) || !(drc[idx] == 'R' && drc[x.second] == 'L')) {
                    st.push(x.second);
                }
            }
        }
        
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        sort(res.begin(), res.end());

        for(auto &ele : res) {
            ele = hlt[ele];
        }
        
        return res;
    }
};

