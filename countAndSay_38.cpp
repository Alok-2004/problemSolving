// leetcode 38
//2:57:38 of Recursion video 4

#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n){
    if(n == 1) return "1";
    string str = countAndSay(n-1);

    // str = 3322251 -> 23321511

    string ztr = "";
    int freq = 1;
    char ch = str[0];
    for(int  i = 1; i<str.length(); i++){
        char dh = str[i];
        if(ch == dh){
            freq++;
        }else{
            ztr = ztr + to_string(freq) + ch;
            freq = 1;
            ch = dh;
        }
    }
    ztr = ztr + to_string(freq) + ch; 
    return ztr;
}

int main(){
    int n;
    cout<<"Entre the number: ";
    cin>>n;
    countAndSay(n);
    return 0;
}