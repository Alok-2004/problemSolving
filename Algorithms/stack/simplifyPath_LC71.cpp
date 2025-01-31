/*
71. Simplify Path
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stack<pair<int, int>>st;
        int i = 0;
        int n = path.size();
        while(i < path.size()){
            if(path[i] == '/'){
                while(i < n  and path[i] == '/'){
                    i++;
                }
                continue;
            }

            int start = i;
            
            if(path[start] == '.'){
                while(i < n and path[i] != '/'){
                    i++;
                }
                if(i - start > 2 or path[i-1] != '.'){
                    st.push({start , i-1});
                }
                else if(i - start == 2){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else continue;
            }
            else if(path[i] != '/'){
                while(i < n and path[i] != '/'){
                    i++;
                }
                st.push({start , i-1});
            }
        }

       while (!st.empty()) {
            string temp = path.substr(st.top().first, st.top().second - st.top().first + 1);
            cout<<temp<<endl;
            res = "/" + temp + res;
            st.pop();
        }

        return res.empty() ? "/" : res;
    }
};

int main(){
	
}
