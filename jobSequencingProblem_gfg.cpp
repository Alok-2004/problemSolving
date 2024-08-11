/*
Job Sequencing Problem
Difficulty: MediumAccuracy: 34.51%Submissions: 237K+Points: 4
Given a set of n jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. 
Deadline of the job is the time on or before which job needs to be completed to earn the profit.
*/
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;    
    int dead;  
    int profit;
};

class Solution 
{
public:
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, [](const Job &a, const Job &b) {
        return a.profit > b.profit;});
        
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        vector<int> temp(maxDeadline + 1, 0);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = arr[i].dead ; j > 0 ; j--){
                if(temp[j] == 0){
                    temp[j] = arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> res(2 , 0);
        for(int i = 0 ; i < temp.size() ; i++){
            if(temp[i] != 0){
                res[0]++;
                res[1] += temp[i];
            }
        }
        
        return res;
    } 
};

int main() {
    Job arr[] = {{1, 11, 321}, {2, 2, 62}, {3, 5, 456}, {4, 8, 394}, {5, 11, 424}, 
                 {6, 10, 22}, {7, 1, 393}, {8, 6, 87}, {9, 3, 118}, {10, 8, 384}, 
                 {11, 10, 83}};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Solution s;
    vector<int> result = s.JobScheduling(arr, n);
    
    for(int i : result)
        cout << i << " ";
    
    return 0;
}

