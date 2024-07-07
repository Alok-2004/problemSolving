#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(vector<string>&res, string s, int n) {
    if (s.length() == n) {
            res.push_back(s);
            return;
        }
        helper(res, s + '1', n);
        if (s.empty() || s[s.size() - 1] == '1')   helper(res, s + '0', n);
    }


    vector<string> validStrings(int n) {
        vector<string>res;
        helper(res, "", n);    
        return res;
    }

int main() {
    int n = 3; 
    vector<string> validStrings = findAllValidStrings(n);

    for (const string& s : validStrings) {
        cout << s << endl;
    }

    return 0;
}

