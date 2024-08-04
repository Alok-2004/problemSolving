#include <iostream>
#include <vector>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> nums(n, 0);
    for(size_t i = 0; i < bookings.size(); i++){
        for(size_t j = bookings[i][0]; j <= bookings[i][1]; j++){
            nums[j-1] = nums[j-1] + bookings[i][2];
        }
    }
    return nums;
}

int main() {
    vector<vector<int>> bookings = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };
    int n = 5;

    vector<int> result = corpFlightBookings(bookings, n);

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
