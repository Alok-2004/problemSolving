#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int reverse(int x) {
    bool flag = false;
    if(x < 0){
        x = abs(x);
        flag = true;
    }
    long long reverse = 0;

    while(x > 0){
        int y = x % 10;
        if(reverse * 10 > INT_MAX){
            return 0;
        }
        else reverse = reverse * 10 + y;
        x /= 10;
    }
    if(flag) return -reverse;
    else return reverse;
}

int main() {
    int num = -123;
    cout << "Reversed number of " << num << " is: " << reverse(num) << endl;
    return 0;
}

