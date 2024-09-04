/*
874. Walking Robot Simulation
A robot on an infinite XY-plane starts at point (0, 0) facing north. 
The robot can receive a sequence of these three possible types of commands:

-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point 
obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in 
its current location and move on to the next command.

Return the maximum Euclidean distance that the robot ever gets from the origin 
squared (i.e. if the distance is 5, return 25).


*/

//Time Complexity = O(MlogM+KlogM+N)
//Space Complexity = O(n)
class Solution {
public:
    pair<int, int> solve(set<pair<int, int>>& S, pair<int, int> p, int steps, int direc) {
        while (steps--) {
            if (direc == 0) {
                if (S.find({p.first, p.second + 1}) != S.end()) break;
                p.second++;
            } else if (direc == 1) { 
                if (S.find({p.first + 1, p.second}) != S.end()) break;
                p.first++;
            } else if (direc == 2) { 
                if (S.find({p.first, p.second - 1}) != S.end()) break;
                p.second--;
            } else if (direc == 3) { 
                if (S.find({p.first - 1, p.second}) != S.end()) break;
                p.first--;
            }
        }
        return p;
    }

    int robotSim(vector<int>& c, vector<vector<int>>& obstacles) {
        int temp = 0; // for direction   {"North", "East", "South", "West"}
        pair<int , int> p = make_pair(0 , 0);   
        set< pair<int , int> >S;
        for( auto ele : obstacles){
            S.insert({ele[0] , ele[1]});
        }
        int res = 0;
        for( int i = 0; i < c.size() ; i++){
            if(c[i] < 0){
                if(c[i] == -1){
                    if(temp == 3) temp = 0;
                    else temp++;
                }
                if( c[i] == -2){
                    if(temp == 0) temp = 3;
                    else temp--;
                } 
            }else{
                p = solve(S , p , c[i] , temp);
            }
            res = max(res , p.first * p.first + p.second * p.second);
        }

        return res;
    }
};
