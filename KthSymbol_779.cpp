#include <iostream>
#include <cmath>

using namespace std;

int kthGrammar(int n, int k) {
    // Base case: when n is 1, return 0 as the first row is always 0
    if (n == 1) return 0;

    // If k is even, the value is flipped compared to the previous row's k/2 position
    if (k % 2 == 0) {
        int preAns = kthGrammar(n - 1, k / 2);
        if (preAns == 0) return 1;
        else return 0;
    } 
    // If k is odd, the value is the same as the previous row's (k/2 + 1) position
    else {
        int preAns = kthGrammar(n - 1, (k / 2) + 1);
        return preAns;
    }
}

int main() {
    int n = 4, k = 5;
    cout << "The " << k << "th element in the " << n << "th row is: " << kthGrammar(n, k) << endl;
    return 0;
}
