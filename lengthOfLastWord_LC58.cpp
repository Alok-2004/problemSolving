class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = s.size();
        int li = -1;
        for(int i = sz - 1; i >= 0; i--){
            if(s[i] != ' '){
                li = i;
                break;
            }
        }
        int res = 0;
        for(int i = li; i >= 0; i--){
            if(s[i] != ' '){
                res++;
            }
            else break;
        }

        return res;
    }
};
