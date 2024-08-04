#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int n = satisfaction.size();
    int suff[n];
    suff[n-1] = satisfaction[n-1];
    for(int i = n-2; i>=0; i--){
        suff[i] = suff[i+1] + satisfaction[i];
    }

    // find the pivot element
    int pivot ;
    for(int i = 0; i<n ; i++){
        if(suff[i] >= 0){
            pivot = i;
            break;
        }
    }

    int output = 0;
    int x = 1;
    for(int i = pivot; i<n; i++){
        output = output + x * satisfaction[i];
        x++;
    }

    return output;
}

int main(){
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << "Maximum satisfaction: " << maxSatisfaction(satisfaction) << endl;
    return 0;
}
