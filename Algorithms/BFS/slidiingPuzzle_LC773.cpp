/*
773. Sliding Puzzle
On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. 
A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. 
If it is impossible for the state of the board to be solved, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

// Using BFS
class Solution {
public:
    string vectorToString(vector<vector<int>>& board) {
        string result;
        for (const auto& row : board)
            for (int cell : row)
                result += to_string(cell);
        return result;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450", start = vectorToString(board);
        if (start == target) return 0;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            int zeroPos = curr.find('0'), zeroRow = zeroPos / 3, zeroCol = zeroPos % 3;
            for (auto& dir : directions) {
                int newRow = zeroRow + dir[0], newCol = zeroCol + dir[1];
                if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3) {
                    int newPos = newRow * 3 + newCol;
                    string next = curr;
                    swap(next[zeroPos], next[newPos]);
                    if (next == target) return steps + 1;
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};


//will give stack overflow
/*
class Solution {
public:
    int solve(vector<vector<int>>& reference, vector<vector<int>>& curr, int m, int n) {
        
        if (curr == reference) {
            return 0;
        }

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = INT_MAX;

        for (auto& dir : directions) {
            int newM = m + dir[0];
            int newN = n + dir[1];

            if (newM >= 0 && newM < curr.size() && newN >= 0 && newN < curr[0].size()) {
                swap(curr[m][n], curr[newM][newN]);
                res = min(res, solve(reference, curr, newM, newN));
                swap(curr[m][n], curr[newM][newN]);
            }
        }

        return res == INT_MAX ? INT_MAX : res + 1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> reference = {{1, 2, 3}, {4, 5, 0}};
        int m = 0, n = 0;

        for (int i = 0; i < board.size(); i++) {
        bool found = false;
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                m = i;
                n = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }
        int res = solve(reference, board, m, n);
        return res == INT_MAX ? -1 : res;
    }
};
*/

int main(){
	
}
