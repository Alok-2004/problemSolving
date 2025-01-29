/*
2550. Count Collisions of Monkeys on a Polygon
There is a regular convex polygon with n vertices. The vertices are labeled from 0 to n - 1 in a clockwise direction, and each vertex has exactly one monkey. 
The following figure shows a convex polygon of 6 vertices.
*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
class Solution {
public:
    int p(int n){
        int res = 1;
        int x = 2;
        while(n > 0){
            if(n % 2 == 1){
                res = (static_cast<long long>(res) * x) % MOD;
                n--;
            }else{
                x = (static_cast<long long>(x) * x) % MOD;
                n /= 2;
            }
        }
        return res % MOD;
    }
    
    int monkeyMove(int n) {
        return (p(n) - 2 + MOD) % MOD;
    }
};

int main(){
	
}
