// to print all the permutaion in increasing order and get n permut

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// this process will not work since time and space complexity will exceed
/*
void permutation(vector<string> &v, string ans, string orig){
    if(orig == ""){
        v.push_back(ans);
        return;
    }
    for(int i = 0; i<orig.length(); i++){
        char ch = orig[i];
        string left = orig.substr(0,i);
        string right = orig.substr(i+1);
        permutation(v, ans + ch, left + right);
    }
}

string getPermutation(int n, int k){
    vector<string> v;
    string str = "";
    for(int i = 1; i <= n; i++){
        str += to_string(i);
    }
    permutation(v, "", str);
    return v[k-1];
}
*/

string helper(string str, int k, string ans){
    int n = str.length();
    if( n == 0) return ans;
    int fact = 1;
    for(int i = 2; i<=n-1; i++){
        fact *= i;
    }

    int idx = k/fact;
    if( k % fact == 0) idx--;
    char ch = str[idx];
    string left = str.substr(0,idx);
    string right = str.substr(idx+1); 
    int q = 1;
    if(k % fact == 0)   q = fact;
    else  q = k % fact;
    return helper(left + right, q, ans + ch);
}

string getPermutation(int n, int k){
    string str = "";
    for(int i = 1; i <= n; i++){
        str += to_string(i);
    }
    return helper(str, k, "");    
}

int main(){
    int n = 9;
    int k = 4;
    cout << getPermutation(n, k) << endl;
    return 0;
}