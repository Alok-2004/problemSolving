#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    vector<int> num;
    int siz = digits.size() - 1;

    for(int i = siz; i>=0 ; i--){
        int x = digits[i] + carry;
        digits[i] = x%10;
        carry = x / 10;
        num.push_back(digits[i]);
    }

    if(carry > 0){
        num.push_back(carry);
    }
    reverse(num.begin(), num.end());
    return num;
}

int main() {
    vector<int> digits = {1, 2, 3};
    vector<int> result = plusOne(digits);
    for (int digit : result) {
        cout << digit << " ";
    }
    return 0;
}

