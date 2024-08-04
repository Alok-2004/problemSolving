#include<iostream>
#include<string>
using namespace std;

string isPalindrome(int x) 
{
    long long multiple = 0;
    for(int i = x; i>0; i = i/10)
    {
        int y = i%10;
        multiple = multiple * 10 + y;
    }
    if(multiple == x) return "true";
    else return "false";
}
int main()
{
	int x;
	cout<<"Enter the number: ";
	cin>>x;
	
	cout<<"Is 'x' a palindrome "<<isPalindrome(x);
	return 0;
}
