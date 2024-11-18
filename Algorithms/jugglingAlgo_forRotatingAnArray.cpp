#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;
    int gcd = __gcd(n, d);

    for (int i = 0; i < gcd; ++i) {
        int temp = arr[i];
        int j = i;

        while (true) {
            int k = (j + d) % n;
            if (k == i) break;

            arr[j] = arr[k];
            j = k;
        }

        arr[j] = temp;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;

    rotateArray(arr, d);

    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";

    return 0;
}

