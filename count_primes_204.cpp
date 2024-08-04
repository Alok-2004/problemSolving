#include<iostream>
#include<cmath>

using namespace std;

// Time complexity is 0f O(n * sqrt(n))
/*
bool isPrime(int number){
    bool flag = true;
    if(number == 1)  return false;

    for(int i = 2; i*i <= number; i++){
        if(number % i == 0){
            flag = false;
            break;
        }
    }

    return flag;
}

int countPrimes(int n){
    if(n == 1 && n == 0)  return 0;
    int count = 0;
    for(int i = 1; i<n; i++){
        if(isPrime(i)) count++;
    }

    return count;
}
*/

// Sieve of Eratosthenesis -> grid
int main(){
    int n = 20;
    cout<<countPrimes(n);
}