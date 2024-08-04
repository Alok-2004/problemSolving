#include<iostream>
#include<string>
#include<vector>

using namespace std;


int minimumLength(string s) {

    if(s.size() == 1){
        return 1;
    }
    int left = 0;
    int i = 0;
    int right = s.size() - 1;
    string a = "";
    while(left < right){
    char check = s[i];  

    cout<<endl<<"right"<<right <<" "<<"left "<<left<<endl;
    
    if(check == s[right]){
            while(left <= right && right >= 0 && s[right] == check){
                 right--;
                 cout<<"right "<<right<<" ";
                 }

            while(left <= right && s[left] == check  )  {
                
                left++;         
                cout<<"left "<<left<<" ";

                }}
        else{
            a += check;
            cout<<endl<<a<<endl;
            i = left;
            break;
        }
        i = left;
    }
        cout<< - left + right;
        return a.size();
}

int main(){
    string s = "aabccabba";

    minimumLength(s);
}