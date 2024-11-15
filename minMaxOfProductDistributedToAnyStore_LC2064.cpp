/*
2064. Minimized Maximum of Products Distributed to Any Store
You are given an integer n indicating there are n specialty retail stores. 
There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. 
You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.
*/

#include<bits/stdc++.h>
using namespace std;



/*
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int local = 0;
        for(auto ele : q){
            local += ele;
        }
        local = static_cast<int>(ceil(static_cast<double>(local) / n));
        int res = local;
        cout<<"local" << local<<endl;
        vector<pair<int , int> >rem; //remainder , space 
        for(int i = 0 ; i < q.size() ; i++){
            if(q[i] <= local){
                n = n - 1;
            }else{
                int x = q[i] / local;
                n = n - x;
                cout<< q[i] - (x * local)<<endl;
                if(q[i] - (x * local) > 0) rem.push_back(make_pair(q[i] - (x * local) , x));
            }
        }

        if(rem.size() == 0 or rem.size() == n){
            return res;
        }else{
            
            cout<<"n "<<n<<endl;

            sort(rem.begin(), rem.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return (static_cast<double>(a.first) / a.second) < (static_cast<double>(b.first) / b.second);
            });

            for(int i = 0 ; i < n ; i++){
                rem.pop_back();
            }
            for(int i = 0; i < rem.size() ; i++){
                int curr = local + rem[i].first / rem[i].second;
                // if(rem[i].first % rem[i].second)
                cout<<curr<<endl;
                res = max(res , curr);  
                
            }
            return res;
        }
    }
};
*/

//Using Binary Search
class Solution {
public:
    bool possibleToDistr(int mid, vector<int>& q, int n) {
        int count = 0;
        for (int i = 0; i < q.size(); i++) {
            count += (q[i] + mid - 1) / mid;
		}
        return count <= n;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int m = q.size();
        int l = 1;
        int r = *max_element(q.begin(), q.end());
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possibleToDistr(mid, q, n)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};
int main(){
	
}
