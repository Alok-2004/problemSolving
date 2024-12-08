/*
3243. Shortest Distance After Road Addition Queries I
You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, 
you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], 
answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.
*/


// Wil update for Floyd-Warshall algorithm


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(vector<list<int>>& temp){
        int n = temp.size();
        int res = 0;
        queue<int>q;
        q.push(0);
        unordered_set<int>visited;
        while(!q.empty()){
            int curr = q.size();
            for(int i = 0; i < curr; i++) {
                int ver = q.front();
                q.pop();
                
                if(ver == n-1){  
                    return res;
                }
                for (int ele : temp[ver]) {
                    if (!visited.count(ele)) {
                        visited.insert(ele);
                        q.push(ele);
                    }
                }
                   
            }
            res = res + 1; 
        }
        return -1;
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<list<int> >temp(n);
        
        for(int i = 0; i < n; i++){
            temp[i].implace_back(i+1);
        }
        
        vector<int>res(q.size() , 0);
        
        for(int i = 0 ; i < q.size() ; i++){
            temp[q[i][0]].implace_back(q[i][1]);
            res[i] = bfs(temp);
        }
        
        return res;
    }
};

int main(){
	
}
