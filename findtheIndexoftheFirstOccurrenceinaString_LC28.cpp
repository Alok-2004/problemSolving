Find the Index of the First Occurrence in a String

class Solution {
public:
    int strStr(string h, string n) {
        int nS = n.size();
        int hS = h.size();

        int res = -1;

        for(int i = 0; i<= hS - nS; i++){
            if(n[0] == h[i]){
                string str = h.substr(i, nS);  //arguement for substr function is starting index and length
                if(str == n){
                    res = i;
                    break;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        int nIndex = 0;
        for(int i=0; i<hLen; i++){
            if(haystack[i]==needle[nIndex]){
                nIndex++;
            }
            else{
                i=i-nIndex;
                nIndex=0;
            }
            if(nIndex==nLen){
                return i-nLen+1;
            }
        }
        return -1;
    }
};
