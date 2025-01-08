/*
1769. Minimum Number of Operations to Move All Balls to Each Box
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.
*/

#include<bits/stdc++.h>
using namespace std;

//Brute Force
/*
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length());
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            if (boxes[currentBox] == '1') {
                for (int newPosition = 0; newPosition < boxes.length();
                     newPosition++) {
                    answer[newPosition] += abs(newPosition - currentBox);
                }
            }
        }
        return answer;
    }
};
*/

 //My Approach + help 
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int leftball = 0 , leftmoves = 0;
        int rightball = 0 , rightmoves = 0;

        vector<int>res(boxes.size() , 0);
        
        // for leftside 
        for(int i = 0 ; i < boxes.size() ; i++){
            res[i] = leftmoves;
            leftball += boxes[i] - '0';
            leftmoves += leftball;
        }

        // for rightside
        for(int i = boxes.size() - 1 ; i >= 0; i--){
            res[i] += rightmoves;
            rightball += boxes[i] - '0';
            rightmoves += rightball;
        }

        return res;

    }
};

int main(){
}
