/*
853. Car Fleet
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, 
where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in 
miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the 
slower car.

A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum 
speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the 
car fleet.

Return the number of car fleets that will arrive at the destination.
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector< pair<int , float> >cars;
        for(int i = 0 ; i < position.size() ; i++ ){
            pair<int , float> temp= make_pair( target-position[i] , static_cast<float>(target-position[i])/speed[i] );
            cars.push_back(temp);
        }

        sort(cars.rbegin() , cars.rend());

        stack< pair<int , float> >s;
        s.push(cars[0]);
        for(int i = 1 ; i < position.size() ; i++){
            auto curr = cars[i];
            while(!s.empty() and s.top().second <= curr.second){
                s.pop();
            }
            s.push(curr);
        }

        return s.size();
    }
};
