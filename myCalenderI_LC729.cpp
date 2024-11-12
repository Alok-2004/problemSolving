/*
729. My Calendar I
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), 
the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. 
Otherwise, return false and do not add the event to the calendar.
*/

#include<bits/stdc++.h>
using namespace std;

class MyCalendar{
public:
    vector<pair<int, int>> overallBookings;

    MyCalendar(){}

    bool checkOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    bool book(int start, int end) {
        for(pair<int, int> region : overallBookings) {
            if(checkOverlap(region.first, region.second, start, end)) {
                return false;
            }
        }

        overallBookings.push_back({start, end});
        return true;
    }
};

int main(){
	
}
