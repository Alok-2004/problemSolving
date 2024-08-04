#include<iostream>
#include<vector>

using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        // the window with the most loss of satisfaction
        int k = minutes;
        int arrSize = n;
        int maxLoss = 0;
        int prevLoss = 0;
        for(int i = 0; i<k; i++){
            if(grumpy[i] == 1)  prevLoss += customers[i];
        }

        maxLoss = prevLoss;
        int maxInd = 0;
        int surrLoss = 0;
        int i = k;
        while(i < n){
            surrLoss = prevLoss;
            if(grumpy[i] == 1) surrLoss += customers[i];
            if(grumpy[i-k] == 1) surrLoss -= customers[i-k];
            if(maxLoss < surrLoss){
                maxLoss = surrLoss;
                maxInd = i - k + 1;
            }
            prevLoss = surrLoss;
            i++;
        }

        // filling 0s in the grumpy arrays windows
        for(int i = maxInd; i < maxInd + k; i++){
            grumpy[i] = 0;
        }

        // sum of satisfaction
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }

        return sum;
    }

int main() {
    vector<int> customers = {1,  1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    int result = maxSatisfied(customers, grumpy, minutes);
    cout << "Maximum satisfied customers: " << result << endl;

    return 0;
}
