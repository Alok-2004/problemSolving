/*
A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.
*/

#include <iostream>
#include <cmath>

bool checkPerfectNumber(int num) {
    if(num == 1){
        return false;
    }

    int sum = 0;
    for(int i = 1; i*i <=  num; i++){
        if( num % i == 0)  sum += i;
    }

    for(int i = sqrt( num); i>= 1; i--){
        if( num % i == 0) sum += num/i;
    }

    sum -= num;
    return (sum == num);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (checkPerfectNumber(num)) {
        std::cout << num << " is a perfect number." << std::endl;
    } else {
        std::cout << num << " is not a perfect number." << std::endl;
    }

    return 0;
}
