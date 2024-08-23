/*
592. Fraction Addition and Subtraction
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. 
If your final result is an integer, change it to the format of a fraction that has a denominator 1. 
So in this case, 2 should be converted to 2/1.
*/

#include<bits/stdc++.h>
using namespace std;

//Coverversion of fraction to decimal and back to decimal is not always same
/*
class Solution {
public:
    int gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    string decimalToFraction(double num) {
        long long integer = static_cast<long long>(num);
        double fractionPart = num - integer;

        long long numerator = round(fractionPart * 1e7);
        long long denominator = 1e7;

        long long hcf = gcd(numerator, denominator);

        numerator /= hcf;
        denominator /= hcf;

        numerator = denominator * integer + numerator;

        return to_string(numerator) + "/" + to_string(denominator);
    }

    string fractionAddition(string ex) {
        double result = 0.0;
        char op = '+';
        
        int i = 0;
        while(i < ex.size()){
        	if(ex[i] == '-' or ex[i] == '+'){
				op = ex[i];
				i++;
			}
			else if( ex[i] >= '0' and  ex[i] <= '9'){
				int numerator = 0;
                while (i < ex.size() and isdigit(ex[i])) {
                    numerator = numerator * 10 + (ex[i] - '0');
                    i++;
                }
                i++;
                int denominator = 0;
                while (i < ex.size() and isdigit(ex[i])) {
                    denominator = denominator * 10 + (ex[i] - '0');
                    i++;
                }
                double temp = static_cast<double>(numerator) / denominator;
                if(op == '+') result += temp;
                else result -= temp;
			} 
		}
		
		string ans = decimalToFraction(result);
		return ans;
    }
};
*/

class Solution {
public:
    int gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    string fractionAddition(string ex) {
        long long numerator = 0, denominator = 1;
        int sign = 1;
        int i = 0;

        while (i < ex.size()) {
            if (ex[i] == '-' || ex[i] == '+') {
                sign = (ex[i] == '-') ? -1 : 1;
                i++;
            }

            long long num = 0;
            while (i < ex.size() && isdigit(ex[i])) {
                num = num * 10 + (ex[i] - '0');
                i++;
            }
            num *= sign;

            i++;

            long long den = 0;
            while (i < ex.size() && isdigit(ex[i])) {
                den = den * 10 + (ex[i] - '0');
                i++;
            }

            numerator = numerator * den + num * denominator;
            denominator *= den;

            long long g = gcd(abs(numerator), denominator);
            numerator /= g;
            denominator /= g;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        return to_string(numerator) + "/" + to_string(denominator);
    }
};

int main(){
	
}
