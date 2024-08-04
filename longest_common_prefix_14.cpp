#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    // {"flower", "flow", "flight"}
    vector<string> str;
    str.push_back("flower");
    str.push_back("flow");
    str.push_back("flight");
    
    for(int  i = 0; i<str.size(); i++)
    {
        cout<<str[i]<<" ";  //flower flow flight
    }
    cout<<endl;
    
    sort(str.begin(), str.end());

    for(int  i = 0; i<str.size(); i++)
    {
        cout<<str[i]<<" "; //flight flow flower sorted acc. to the dictionary or lexogarphically
    }
    cout<<endl;

    int n = 0;
    string str1 = str[0];
    string str2 = str[str.size() - 1];
    string s = "";
    for(int i = 0; i<=min(str1.size(),str2.size()); i++)
    {
        if(str1[i] == str2[i])
        {
            s = s + str1[i];
        }
        else break;
    }
    cout<<s;

}
