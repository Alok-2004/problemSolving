#include<iostream>
#include<vector>
using namespace std;

// in this number of closing brackets is always smaller/eqaul to opening brackets

void bracket(string ans, int open, int close, int n){
    if(close == n){
        cout<<ans<<endl;
        return;
    }
    // always closing < open && opening > open

    if(open < n){
        bracket(ans + "(", open + 1, close, n);
    }
    if(close < open){
        bracket(ans + ")", open, close + 1, n);
    }

}

int main(){
    int n;
    cout<<"Number of brackets: ";
    cin>>n;

    bracket("", 0, 0, n);

}

// check at 1:50
