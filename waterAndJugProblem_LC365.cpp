/*
365. Water and Jug Problem
You are given two jugs with capacities x liters and y liters. 
You have an infinite water supply. Return whether the total amount of water in both jugs may reach target using the following operations:

Fill either jug completely with water.
Completely empty either jug.
Pour water from one jug into another until the receiving jug is full, 
or the transferring jug is empty.
*/

#include<bits/stdc++.h>
using namespace std;

//Mathematical
/*
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == 0) return true;

        int g = gcd(x, y);
        return target % g == 0;
    }
};
*/

//Using BFS 
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == 0) return true;
        
        unordered_set<string> visited;
        return dfs(0, 0, x, y, target, visited);
    }

private:
    bool dfs(int a, int b, int x, int y, int target, unordered_set<string>& visited) {
        string state = to_string(a) + "," + to_string(b);
        if (visited.count(state)) return false;
        visited.insert(state);
        
        if (a == target || b == target || a + b == target) return true;

        return dfs(x, b, x, y, target, visited) ||
               dfs(a, y, x, y, target, visited) ||
               dfs(0, b, x, y, target, visited) ||
               dfs(a, 0, x, y, target, visited) ||
               dfs(max(0, a - (y - b)), min(y, b + a), x, y, target, visited) ||
               dfs(min(x, a + b), max(0, b - (x - a)), x, y, target, visited);
    }
};

