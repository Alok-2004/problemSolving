#include<iostream>
#include<cmath>

using namespace std;

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

int smallestValue(int num) {

    if(isPrime(num))  return num;
    

    int sum = 0;
    for(int i = 1; i*i <  num; i++){
        if( num % i == 0  && isPrime(i)){
            int m = num;
            while(m%i == 0){
                sum += i;
                m /= i;
            }
        }
    }

    for(int i = sqrt( num); i>= 1; i--){
        if( num % i == 0  && isPrime(num/i)){
            int m = num;
            while(m % (num/i) == 0){
                sum += (num/i);
                m/= (num/i);
            }
    }
    }
    if(sum == 4)  return 4;
    return smallestValue(sum);
}

int main(){
    int number = 4;
    int nas = smallestValue(number);
 
    cout<<nas;
}