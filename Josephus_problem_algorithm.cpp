//Josephus problem algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k){
      int res = 0;
      for(int i = 1; i<=n; i++){
        res = ( k + res ) % i;
      }
      return res + 1;
    }
};
