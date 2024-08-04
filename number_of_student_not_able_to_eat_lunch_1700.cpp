class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& s) {
        queue<int>q; // students
		// vector of sandwiches will act like stack
        for(int i = 0; i < students.size(); i++){
            q.push(students[i]);
        }

        int i = 0;
        int ans = 0;

        while(q.size() > 0 && ans != q.size()){
            if(q.front() == s[i]){
                q.pop();
                i++;
                ans = 0;
            }else{
                q.push(q.front());
                q.pop();
                ans++;
            }
        }

        return ans;
    }
};
