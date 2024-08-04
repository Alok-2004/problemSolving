#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.size();
        bool flag = false; 
        
        for (int len = 1; len <= n / 2; len++) 
        {
            if (n % len == 0) 
            {
                string pattern = s.substr(0, len); 
                flag = true;                 
                for (int i = len; i < n; i += len) 
                {
                    if (s.substr(i, len) != pattern) 
                    {
                        flag = false;
                        break;
                    }
                }
                
                if (flag) return true;                
            }
        }
        
        return false; 
    }
};

int main() 
{
    Solution solution;
    
    string input1 = "abab";
    bool result1 = solution.repeatedSubstringPattern(input1);
    cout << "Result for input1 (abab): " << (result1 ? "true" : "false") << endl;
    
    string input2 = "abcabcabc";
    bool result2 = solution.repeatedSubstringPattern(input2);
    cout << "Result for input2 (abcabcabc): " << (result2 ? "true" : "false") << endl;

    string input3 = "aaaa";
    bool result3 = solution.repeatedSubstringPattern(input3);
    cout << "Result for input3 (aaaa): " << (result3 ? "true" : "false") << endl;

    return 0;
}
