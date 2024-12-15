/*
1792. Maximum Average Pass Ratio
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pp;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int ex) {
        auto comparator = [](const pp& a, const pp& b) {
            double gainA = ((a.first + 1.0) / (a.second + 1.0)) - (a.first * 1.0 / a.second);
            double gainB = ((b.first + 1.0) / (b.second + 1.0)) - (b.first * 1.0 / b.second);
            return gainA < gainB;
        };

        priority_queue<pp , vector<pp> , decltype(comparator)>pq(comparator);
        
        for (const auto& pair : c) {
            pq.push({pair[0], pair[1]});
        }

        while(ex-- > 0){
            auto curr = pq.top();
            pq.pop();
            curr.first += 1;
            curr.second += 1;
            pq.push(curr);
        }
        float temp = 0.0;
        while(!pq.empty()){
            auto curr = pq.top();
            temp += curr.first / (curr.second * 1.0);
            pq.pop();
        }

        return temp / c.size();
    }
};

int main(){
	
}
