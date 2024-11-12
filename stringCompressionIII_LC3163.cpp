/*
3163. String Compression III
Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        int j = 0; 
        int count = 0;
        string res = "";
        while(j < word.size()){
            if(word[i] == word[j] && count < 9){
                count++;
            }else{
                res += to_string(count) + word[i];
                /*
        		 res = res + to_string(count) + word[i];
				 It consumes more memory as it first make temp string and then passes it 
				 res whereas when we use += it chages the res in place         
                */
                count = 1;
                i = j;  
            }
            j++;
        }
        res += to_string(count) + word[i];
        // res = res + to_string(count) + word[i]; 
        return res;
    }
};

int main(){
	
}
