/*
386. Lexicographical Numbers
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
*/

//Not a good method
//Time complexity = nlogn
/*
class Solution {
public:
    static bool cmp(int a,int b){
        return to_string(a) < to_string(b);
    }

    vector<int> lexicalOrder(int n) {
        vector<int>res(n);

        for(int i = 0; i < n ;i++){
            res[i] = i+1;
        }

        sort(res.begin() , res.end() , cmp);
        return res;    
    }
};
*/

//Using Recursion
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int>&res , int n , int start){
        if( start > n) return;
        for(int i = start * 10; i <= start*10 + 9; i++){
            if(i > n) break;
            res.push_back(i);
            solve(res , n , i);
        };
        return;
    }

    vector<int> lexicalOrder(int n) {
        vector<int>res;

        for(int i = 1; i <= 9; i++){
            if(i > n) break;
            res.push_back(i);
            solve(res , n , i);
        };
        return res;
    }
};	

int main(){
}
