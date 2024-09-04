/*
1894. Find the Student that Will Replace the Chalk
There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, 
then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, 
starting with the student number 0 again.

You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, 
they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], 
then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       vector<long long>pre(chalk.size() , 0);
       pre[0] = chalk[0]; 
       for(int i = 1 ; i < chalk.size() ; i++){
            pre[i] = chalk[i] + pre[i-1];
       }
        k = k % pre[chalk.size() - 1];
       int res = 0;
       for(int i = 0 ; i < chalk.size() ; i++){
            if(pre[i] > k){
                res = i;
                break;
            }
       } 
       return res;
    }
};

int main(){
	
}
