#include<bits/stdc++.h>
using namespace std;

//TC of O(n * k) and SC of O(n)
/*
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i = 1; i<=n; i++)  q.push(i);

        int x = 1;
        while(q.size() > 1){
            if(x < k){
                q.push(q.front());
                q.pop();
                x++;
            }else if(x == k){ 
                x = 1;
                q.pop();
            }
        }
        return q.front();
    }
};
*/
//Josephus problem algorithm


int main(){
	
}
