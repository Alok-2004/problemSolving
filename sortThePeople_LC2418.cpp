/*
2418. Sort the People
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.
*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int , int>uM;
        for( int i = 0; i < names.size() ; i++){
            uM[heights[i]] = i;
        }

        sort( heights.begin() , heights.end() , greater<int>() );
        vector<string>res(names.size());

        for(int i = 0 ; i < names.size() ; i++){
            res[i] = names[ uM[heights[i]] ];
        }
        return res;
    }
};
