/*
875. Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.
*/
class Solution {
public:

    bool check( vector<int>& piles , int temp , int h ){
        long long curr = 0;
        for(int ele : piles){
            long long div = ele / temp;
            curr += div;
            if( ele % temp != 0 ) curr++;
        }

        return curr <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin() , piles.end());
        int res = 0;
        while( lo <= hi){
            int mid = lo + ( hi - lo ) / 2;
            if( !check(piles , mid , h) ){
                lo = mid + 1;
            }
            else{
                res = mid;
                hi = mid - 1;
            }

        }
        return res;    
    }
};
