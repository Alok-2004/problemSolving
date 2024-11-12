/*
2696. Minimum String Length After Removing Substrings
You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if( st.empty() ) st.push(s[i]);
            else{
                if(st.top() == 'A' and s[i] == 'B') {
                    st.pop();
                    continue;
                }
                else if(st.top() == 'C' and s[i] == 'D'){
                    st.pop();
                    continue;
                }
                else st.push(s[i]);
            }
        }

        return st.size();
    }
};

int main(){
	
}
