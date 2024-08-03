/*
The Celebrity Problem
Difficulty: MediumAccuracy: 38.33%Submissions: 258K+Points: 4
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  
A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. 
You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

*/
#include<bits/stdc++.h>
using namespace std;


//TC = O(n^2) && SC = O(n)
/*
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        vector<int>knowsMe(n, 0);
        vector<int>iKnow(n, 0);
        
        int res = -1;
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n ; j++){
                if(mat[i][j] == 1){
                    iKnow[i]++;
                    knowsMe[j]++;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            if(knowsMe[i] == n-1 and iKnow[i] == 0){
                res = i;
                break;
            }
        }
        
        return res;
    }
};
*/

// TC = O(n) and SP = O(1)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        
        int n = mat.size();
        int top = 0;
        int bottom = n-1;
        
        while(top < bottom){
            int i = top;
            int j = bottom;
            if( mat[i][j] == 0 )   bottom--; 
            if( mat[i][j] == 1 )   top++;
        }
        
        int res = top;
        
        for(int i = 0; i < n; i++){
            if(i !=top and mat[top][i] == 1 ){
                res = -1;
                break;
            }
            
            if( i != top and mat[i][top] == 0 ){
                res = -1;
                break;
            }
        }
        
        return res;
        
    }
};


int main(){
	
}
