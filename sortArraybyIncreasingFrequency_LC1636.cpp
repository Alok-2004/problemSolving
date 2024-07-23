/*
1636. Sort Array by Increasing Frequency
Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.
*/

/*
bool com(pair<int, int>&p1 ,  pair<int, int>&p2){
    if(p1.first < p2.first) return true;
    else if( p1.first == p2.first){
        if(p2.second < p1.second) return true;
        else return false;
    }
    else return false;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>uM; //  ele, frequency
        for(int ele : nums){
            uM[ele]++;
        }

        vector< pair<int, int> >temp;
        for(auto x : uM){
            temp.push_back( { x.second  , x.first} );
        }

        sort(temp.begin(), temp.end(), com);

        vector<int>res;
        for(int i = 0 ; i < temp.size() ; i++){
            int x = temp[i].second;
            while(uM[x] > 0){
                res.push_back(x);
                uM[x]--;
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int>uM; //  ele, frequency
        for(int ele : nums){
            uM[ele]++;
        }

        sort(nums.begin(), nums.end(), [&uM](int a, int b){
            if(uM[a] < uM[b]) return true;
            else if( uM[a] == uM[b]){
                if(a > b) return true;
                else return false;
            }
            else return false;
        });

        return nums;
    }
};
