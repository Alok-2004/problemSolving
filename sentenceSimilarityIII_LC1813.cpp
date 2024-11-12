/*
1813. Sentence Similarity III
You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that 
the inserted sentence must be separated from existing words by spaces.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<string>s1 , vector<string>s2){
        int count = s1.size();
        int i = 0;

        while(i < s1.size()){
            if(s1[i] == s2[i]){
                count--;
                cout<<count<<endl;
                i++;
            }else break;
        }

        i = s1.size()-1;
        int j = s2.size()-1;
        while(i >= 0 and j >= 0){
            if(s1[i] == s2[j]){
                count--;
                i--;
                j--;
            }else break;
        }
        return count<=0;
    }

    bool areSentencesSimilar(string s1, string s2) {
        vector<string>temp1;
        vector<string>temp2;
        string curr = "";
        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] != ' ') curr += s1[i];
            else{
                temp1.push_back(curr);
                curr = ""; 
            }
        }

        temp1.push_back(curr);
        curr = "";

        for(int i = 0 ; i < s2.size() ; i++){
            if(s2[i] != ' ') curr += s2[i];
            else{
                temp2.push_back(curr);
                curr = ""; 
            }
        }
        temp2.push_back(curr);
        bool res;
        if(temp1.size() > temp2.size()) res = check(temp2 , temp1);
        else  res = check(temp1 , temp2);
        return res;
    }
};

int main(){
	
}

// will not work beacause 
/*
input s1 = "lucky" s2 = "ludfkjvnky"
*/
/*
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size() > s2.size()) swap (s1 , s2);
        int count = s1.size();
        
        int i = 0;
        while(i <= s1.size()){
            if(s1[i] == s2[i]){
                count--;
                i++;
            }
            else break;
        }

        int n = s1.size()-1;
        int m = s2.size()-1;
        while(n >= 0){
            if(s1[n] == s2[m]){
                count--;
                n--;
                m--;
            }else break;
        }

        return count <= 0;
    }
};
*/


