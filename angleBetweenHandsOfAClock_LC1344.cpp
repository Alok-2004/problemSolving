/*
1344. Angle Between Hands of a Clock
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed 
between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrAngle = (hour % 12) * 30.0 + minutes / 2.0;
        double minAngle = minutes * 6.0;
        double angle = abs(hrAngle - minAngle);
        return min(angle  , 360 - angle); 
    }
};

int main(){
	
}
