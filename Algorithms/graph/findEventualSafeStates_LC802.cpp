/*
802. Find Eventual Safe States
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);
        
        
        queue<int> que;
	    vector<int> indegree(V, 0);
	    int count = 0;
	    for(int u = 0; u < V; u++) {
	        for(int &v : graph[u]) {
                adj[v].push_back(u);
	            indegree[u]++;
	        }
	    }
	    
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    
        vector<bool> safe(V, false);
	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
            safe[u] = true;
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }
	            
	        }
	    }
	    
	    vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

int main(){
	
}
