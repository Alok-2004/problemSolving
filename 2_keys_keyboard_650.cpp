#include<iostream>
#include<vector>

using namespace std;

int greatestDivisor(int n){
    for(int i = n/2; i>=1; i--){
        if(n % i == 0){
            return i;
        }
    }
    return 1;
}

int minSteps(int n){
    int count = 0;
    while( n > 1){
        int hf = greatestDivisor(n);
        count += (n/hf);
        n = hf;
    }
    return count;
}

int main(){
    int number = 20;
    cout<<minSteps(number);

    return 0;
}