/*
Q1. Find the Number of Winning Players
You are given an integer n representing the number of players in a game and a 2D array pick where pick[i] = [xi, yi] 
represents that the player xi picked a ball of color yi.
Player i wins the game if they pick strictly more than i balls of the same color. In other words,
Player 0 wins if they pick any ball.
Player 1 wins if they pick at least two balls of the same color.
Player i wins if they pick at leasti + 1 balls of the same color.
Return the number of players who win the game.
Note that multiple players can win the game
*/

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map< int, unordered_map<int, int> > uM;

        for(auto arr : pick) {
            int p = arr[0];
            int c = arr[1];
            uM[p][c]++;
        }

        int winningPlayersCount = 0;

        for(int i = 0; i < n; ++i){
            for (auto colorCount : uM[i]) {
                if (colorCount.second >= i + 1) {
                    winningPlayersCount++;
                    break;
                }
            }
        }

        return winningPlayersCount;
    }
};
