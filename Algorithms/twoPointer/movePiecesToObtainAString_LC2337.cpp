/*
2337. Move Pieces to Obtain a String
You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.
*/

#inlcude<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        for(int i = 0 ,j = 0 ; i < start.size() and j < target.size() ; i++ , j++){
            while(i < start.size() and start[i] == '_') i++;
            while(j < target.size() and target[j] == '_') j++;

            char ch = start[i];
            if(ch != target[j]) return false;
            if(ch == 'R' and i > j) return false;
            if(ch == 'L' and i < j) return false; 
        }
        return true;        
    }
};

int main(){
	
}
