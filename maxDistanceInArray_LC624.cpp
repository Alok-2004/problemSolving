/*
624. Maximum Distance in Arrays
You are given m arrays, where each array is sorted in ascending order.
You can pick up two integers from two different arrays (each array picks one) and calculate the distance. 
We define the distance between two integers a and b to be their absolute difference |a - b|.
Return the maximum distance
*/

class Solution {
public:
    static int maxDistance(vector<vector<int>>& arrays) {
        int xMin=arrays[0][0], xMax=arrays[0].back();
        int diff=0;
        int m=arrays.size();
        //1 pass 
        for(int i=1; i<m; i++){
            vector<int> arr=arrays[i];
            int a0=arr[0], aN=arr.back();
            diff=max({diff, aN-xMin, xMax-a0});
            xMin=min(a0, xMin);
            xMax=max(aN, xMax);
        }
       
        return diff;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>>mxpq; // max heap number , and index of the array
        priority_queue<pair<int,int>, vector< pair<int, int>>, greater<pair<int,int>> >minpq;

        for(int i = 0 ; i < arrays.size(); i++){
            minpq.push( {arrays[i][0] , i} );
            mxpq.push( {arrays[i].back() , i} );
        }

        int res = 0;

        while(true){
            if(minpq.top().second != mxpq.top().second){
                res = mxpq.top().first - minpq.top().first;
                break;
            }else{
                auto x = minpq.top();
                auto y = mxpq.top();
                
                mxpq.pop();
                minpq.pop();

                int a = abs(x.first - mxpq.top().first);
                int b = abs(y.first - minpq.top().first);

                if( a > b){
                    minpq.push(x);
                }else{
                    mxpq.push(y);
                }
            }
        }

        return res;          
    }
};
