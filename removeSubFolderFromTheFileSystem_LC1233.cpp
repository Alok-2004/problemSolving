/*
1233. Remove Sub-Folders from the Filesystem
Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it. 
A sub-folder of folder[j] must start with folder[j], followed by a "/". 
For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end());
        
		vector<string>result;
        result.push_back(folder[0]);
        
		string temp = folder[0];
        for(int i = 1 ; i < folder.size() ; i++){
            temp = result.back() + '/';
            string curr = folder[i].substr(0 , temp.size());
            if(curr != temp){
                result.push_back(folder[i]);
            }
        }
        return result;
    }
};

int main(){
	
}
