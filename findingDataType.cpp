#include<bits/stdc++.h>
using namespace std;

int main(){
	string num1;
	getline(num1, cin);
	
//	Now Cheking
	int i = 0;
	double j = 0.00;
	bool isDouble = false;
	for( char ch : num1){
		if(isDouble){
			cout<<"Out of format";
		}
		if(ch == '.'){
			isDouble = true;
		}
	}
	
	if(isDouble){
		j = stod(num1);
		cout<<j<<" is a double";
	}
	else
	{
		i = stoi(num1);
		cout<<i<<" is a integer";
	}
	
}
