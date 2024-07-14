class Solution {
public:
    string getSmallestString(string s) {
        int i = 0;
        if(s.size() < 2) return s;
        int j = 1;
        while(j < s.size()){
            if(s[i] > s[j]){
                if( (s[i] - '0') % 2 == 0 && (s[j] - '0') % 2 == 0){
                    swap(s[i], s[j]);
                    break;
                }
                else if( (s[i] - '0') % 2 != 0 && (s[j] - '0') % 2 != 0 ){
                    swap(s[i], s[j]);
                    break;
                }
            }
            j++;
            i++;
        }

        return s;
    }
};
