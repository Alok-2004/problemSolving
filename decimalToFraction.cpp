#include<bits/stdc++.h>
using namespace std;

int gcd(long long a , long long b){
	if (b == 0)
        return a;
    return gcd(b, a % b);
}

string decimalToFraction(double num){
	long long integer = static_cast<long long>(num);
	double fractionPart = num - integer;
	
	long long numerator = round(fractionPart * 1e7);
	long long deno = 1e7;
	
	int hcf = gcd(numerator , deno);
	
	numerator /= hcf;
	deno /= hcf;
	
	numerator = deno * integer + numerator;
	
	string res = to_string(numerator) + "/" + to_string(deno);
	return res;
}

int main(){
	double decimal;
	cout<<"Enter the value: \n";
	cin>>decimal;
	
	cout<<decimalToFraction(decimal);
	
}
