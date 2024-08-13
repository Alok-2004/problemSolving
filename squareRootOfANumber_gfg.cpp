/*
Square root of a number
Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number
*/
typedef long long int ll;
class Solution {
  public:
    ll floorSqrt(ll n) {
        ll i = 0; 
        ll j = n;
        ll res = 0;
        while(i <= j){
            ll mid = i + (j - i)/2;
            
            if(mid * mid == n){
                res = mid;
                break;
            }
            
            if( mid*mid > n){
                j = mid - 1;
            }
            else{ 
                i = mid + 1;
                res = mid;
            }
        }
        
        return res;
    }
};
