#include<iostream>
#include<string>

using namespace std;

    int myAtoi(string s) {
        long long check = 0;
        
        // for condition 1
        bool flagforminus = false;
        bool flagfornum = false;
        char ch = ' ';

        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            
            if(!flagfornum && !flagforminus && ch == '-'){
                flagforminus = true;
            }

            if( ch <= '9' && ch >= '0'){
                check = check * 10 + (ch - '0');;
                flagfornum = true;
            }
            // condition 2
            if(flagfornum && (ch < '0' || ch > '9') && ch != ' ' && ch != '-' && ch != '+') break;
            if((ch < '0' || ch > '9') && ch != ' ' && ch != '-' && ch != '+') break;

        }

        if(flagforminus && check > INT_MAX) return INT_MIN ;
        else if(!flagforminus && check > INT_MAX)  return INT_MAX - 1;
        else if(flagforminus){
            int ans = -check;
            return ans;
        }
        else{
            int ans = check;
            return ans;
        } 
    }
    
    
int main(){
	string a = "hello232";
	int ans = myAtoi(a);
	cout<< ans;
}
