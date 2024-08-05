/*
N meetings in one room
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] 
is the start time of meeting i and end[i] is the finish time of meeting i. 
Return the maximum number of meetings that can be accommodated in a single meeting room, 
when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/

class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        
        int res = 0;
        vector< pair<int , int>>tim;
        for(int i = 0 ; i < n ; i++){
            tim.push_back( {start[i] , end[i]} );
        }
        
        sort(tim.begin() , tim.end());
        
        int lastTime = 0;
        for( int i = 0; i < n; i++){
            if( tim[i].first > lastTime){
                res++;
                lastTime = tim[i].second;
            }
            lastTime = min(lastTime , tim[i].second);
        }
        
        return res;
        
    }
};
