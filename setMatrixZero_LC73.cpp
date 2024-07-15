
// Time complexity is O(mn)
// Space complexity is O(mn)
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        set<pair<int, int>> s;

        for(int i = 0; i < m.size(); i++) {
            for(int j = 0; j < m[0].size(); j++) {
                if(m[i][j] == 0) {
                    s.insert({i, j});
                }
            }
        }

        for(auto ele : s) {
            for(int i = 0; i < m[0].size(); i++) {
                m[ele.first][i] = 0;
            }
            for(int i = 0; i < m.size(); i++) {
                m[i][ele.second] = 0;
            }
        }
    }
};
*/

//now Space complexity of O(1) means constant space
class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
    	bool frstRowZero = false;
    	bool frstclmnZero = false;
    	
    	for(int i = 0; i < m[0].size(); i++){
            if(m[0][i] == 0){
                frstRowZero = true;
                break;
            }
        }

		for(int i = 0; i < m.size(); i++){
            if(m[i][0] == 0){
                frstclmnZero = true;
                break;
            }
        }
		
		// creating Markers
		for(int i = 1; i < m.size(); i++){
			for(int j = 1; j<m[0].size(); j++){
				if(m[i][j] == 0){
					m[0][j] = 0;
					m[i][0] = 0;
				}
			}
		}
		
		// Modifing
		for(int i = 1; i < m.size(); i++){
			if(m[i][0] == 0){
				for(int j = 1; j < m[0].size(); j++){
					m[j][i] = 0;
				}
			}
		}
		
		for(int j = 1; i < m[0].size(); j++){
			if(m[j][o] == 0){
				for(int i = 1; i < m.size(); i++){
					m[i][j] = 0;
				}
			}
		}
		
		// Now for 1st row and 1st column
		if(frstRowZero){
			for(int i = 0; i < m[0].size(); i++){
				m[0][i] = 0;
			}
		}
		if(frstclmnZero){
			for(int i = 0; i < m.size(); i++){
				m[i][0] = 0;
			}
		}
		
	}
};





